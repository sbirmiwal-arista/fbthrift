/*
 * Copyright 2017-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <folly/io/IOBuf.h>
#include <glog/logging.h>
#include <stdint.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/protocol/TProtocolException.h>
#include <thrift/lib/cpp/protocol/TProtocolTypes.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/async/ResponseChannel.h>
#include <thrift/lib/cpp2/protocol/Serializer.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>
#include <thrift/lib/cpp2/transport/core/ThriftChannelIf.h>
#include <thrift/lib/thrift/gen-cpp2/RpcMetadata_types.h>
#include <memory>
#include <string>

namespace apache {
namespace thrift {

/**
 * Manages per-RPC state.  There is one of these objects for each RPC.
 *
 * TODO: RSocket currently has a dependency to this class. We may want
 * to clean up our APIs to avoid the dependency to a ResponseChannel
 * object.
 */
class ThriftRequest : public ResponseChannel::Request {
 public:
  ThriftRequest(
      std::shared_ptr<ThriftChannelIf> channel,
      std::unique_ptr<RequestRpcMetadata> metadata)
      : channel_(channel),
        name_(metadata->name),
        kind_(metadata->kind),
        seqId_(metadata->seqId),
        active_(true),
        reqContext_(&connContext_, &header_),
        timer_(channel_->getEventBase()->timer()) {
    header_.setProtocolId(static_cast<int16_t>(metadata->protocol));
    header_.setSequenceNumber(metadata->seqId);
    if (metadata->__isset.clientTimeoutMs) {
      header_.setClientTimeout(
          std::chrono::milliseconds(metadata->clientTimeoutMs));
    }
    if (metadata->__isset.queueTimeoutMs) {
      header_.setClientQueueTimeout(
          std::chrono::milliseconds(metadata->queueTimeoutMs));
    }
    if (metadata->__isset.priority) {
      header_.setCallPriority(
          static_cast<concurrency::PRIORITY>(metadata->priority));
    }
    if (metadata->__isset.otherMetadata) {
      header_.setReadHeaders(std::move(metadata->otherMetadata));
    }
    reqContext_.setMessageBeginSize(0);
    reqContext_.setMethodName(metadata->name);
    reqContext_.setProtoSeqId(metadata->seqId);

    // Server side timeouts
    queueTimeout_.request_ = this;
    taskTimeout_.request_ = this;
  }

  void scheduleTimeouts(
      bool differentTimeouts,
      std::chrono::milliseconds queueTimeout,
      std::chrono::milliseconds taskTimeout) {
    if (differentTimeouts) {
      if (queueTimeout > std::chrono::milliseconds(0)) {
        timer_.scheduleTimeout(&queueTimeout_, queueTimeout);
      }
    }
    if (taskTimeout > std::chrono::milliseconds(0)) {
      timer_.scheduleTimeout(&taskTimeout_, taskTimeout);
    }
  }

  bool isActive() override {
    return active_;
  }

  void cancel() override {
    active_ = false;
    cancelTimeout();
  }

  bool isOneway() override {
    return kind_ == RpcKind::SINGLE_REQUEST_NO_RESPONSE ||
        kind_ == RpcKind::STREAMING_REQUEST_NO_RESPONSE;
  }

  protocol::PROTOCOL_TYPES getProtoId() {
    return static_cast<protocol::PROTOCOL_TYPES>(header_.getProtocolId());
  }

  Cpp2RequestContext* getRequestContext() {
    return &reqContext_;
  }

  void sendReply(
      std::unique_ptr<folly::IOBuf>&& buf,
      apache::thrift::MessageChannel::SendCallback* /*cb*/ = nullptr) override {
    if (isActive()) {
      auto metadata = std::make_unique<ResponseRpcMetadata>();
      metadata->seqId = seqId_;
      metadata->__isset.seqId = true;
      metadata->otherMetadata = header_.releaseWriteHeaders();
      auto* eh = header_.getExtraWriteHeaders();
      if (eh) {
        metadata->otherMetadata.insert(eh->begin(), eh->end());
      }
      if (!metadata->otherMetadata.empty()) {
        metadata->__isset.otherMetadata = true;
      }
      channel_->sendThriftResponse(std::move(metadata), std::move(buf));
    }
  }

  void sendErrorWrapped(
      folly::exception_wrapper ew,
      std::string exCode,
      apache::thrift::MessageChannel::SendCallback* /*cb*/ = nullptr) override {
    if (isActive()) {
      DCHECK(ew.is_compatible_with<TApplicationException>());
      header_.setHeader("ex", exCode);
      ew.with_exception([&](TApplicationException& tae) {
        std::unique_ptr<folly::IOBuf> exbuf;
        auto proto = header_.getProtocolId();
        try {
          exbuf = serializeError(proto, tae, name_, seqId_);
        } catch (const protocol::TProtocolException& pe) {
          // Should never happen.  Log an error and return an empty
          // payload.
          LOG(ERROR) << "serializeError failed. type=" << pe.getType()
                     << " what()=" << pe.what();
        }
        sendReply(std::move(exbuf));
      });
    }
  }

  std::shared_ptr<ThriftChannelIf> getChannel() {
    return channel_;
  }

 private:
  class QueueTimeout : public folly::HHWheelTimer::Callback {
    ThriftRequest* request_;
    void timeoutExpired() noexcept override {
      if (!request_->reqContext_.getStartedProcessing()) {
        request_->cancel();
        if (!request_->isOneway()) {
          request_->channel_->getEventBase()->runInEventBaseThread([this]() {
            request_->sendErrorWrapped(
                TApplicationException(
                    TApplicationException::TApplicationExceptionType::TIMEOUT,
                    "Queue Timeout"),
                kTaskExpiredErrorCode,
                nullptr);
          });
        }
        cancelTimeout();
      }
    }
    friend class ThriftRequest;
  };
  class TaskTimeout : public folly::HHWheelTimer::Callback {
    ThriftRequest* request_;
    void timeoutExpired() noexcept override {
      request_->cancel();
      if (!request_->isOneway()) {
        request_->channel_->getEventBase()->runInEventBaseThread([this]() {
          request_->sendErrorWrapped(
              TApplicationException(
                  TApplicationException::TApplicationExceptionType::TIMEOUT,
                  "Task expired"),
              kTaskExpiredErrorCode,
              nullptr);
        });
      }
      cancelTimeout();
    }
    friend class ThriftRequest;
  };
  friend class QueueTimeout;
  friend class TaskTimeout;
  friend class ThriftProcessor;

  std::shared_ptr<ThriftChannelIf> channel_;
  std::string name_;
  RpcKind kind_;
  int32_t seqId_;
  std::atomic<bool> active_;
  transport::THeader header_;
  Cpp2ConnContext connContext_;
  Cpp2RequestContext reqContext_;

  // Timer is from channel_'s EventBase.
  folly::HHWheelTimer& timer_;
  QueueTimeout queueTimeout_;
  TaskTimeout taskTimeout_;

  void cancelTimeout() {
    queueTimeout_.cancelTimeout();
    taskTimeout_.cancelTimeout();
  }
};
} // namespace thrift
} // namespace apache

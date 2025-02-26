/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/typed-interceptor/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/typed-interceptor/gen-cpp2/MyServiceAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> MyService_echo_pargs;
typedef apache::thrift::ThriftPresult<true> MyService_echo_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<-1, ::apache::thrift::type_class::structure, ::cpp2::Request*>> MyService_getRandomData_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::string, ::std::string*>> MyService_getRandomData_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<-1, ::apache::thrift::type_class::integral, ::std::int32_t*>> MyService_getId_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::integral, ::std::int32_t*>> MyService_getId_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<-1, ::apache::thrift::type_class::structure, ::cpp2::Request*>> MyService_ping_eb_pargs;
typedef apache::thrift::ThriftPresult<true> MyService_ping_eb_presult;
} // cpp2
template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::MyService>::echoT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback) {

  ::cpp2::MyService_echo_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "echo",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "MyService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}

template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::MyService>::getRandomDataT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::cpp2::Request& p_req) {

  ::cpp2::MyService_getRandomData_pargs args;
  args.get<0>().value = const_cast<::cpp2::Request*>(&p_req);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "getRandomData",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "MyService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}

template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::MyService>::getIdT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_field) {

  ::cpp2::MyService_getId_pargs args;
  args.get<0>().value = &p_field;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "getId",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "MyService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}

template <typename Protocol_, typename RpcOptions>
void apache::thrift::Client<::cpp2::MyService>::ping_ebT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::cpp2::Request& p_req) {

  ::cpp2::MyService_ping_eb_pargs args;
  args.get<0>().value = const_cast<::cpp2::Request*>(&p_req);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "ping_eb",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "MyService");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::forward<RpcOptions>(rpcOptions), std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);
}



void apache::thrift::Client<::cpp2::MyService>::echo(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  echo(rpcOptions, std::move(callback));
}

void apache::thrift::Client<::cpp2::MyService>::echo(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto [ctx, header] = echoCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  echoImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback));
}

void apache::thrift::Client<::cpp2::MyService>::echoImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        echoT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback));
      } else {
        echoT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        echoT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback));
      } else {
        echoT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::MyService>::echoCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      getServiceName(),
      "MyService.echo",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::cpp2::MyService>::sync_echo() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_echo(rpcOptions);
}

void apache::thrift::Client<::cpp2::MyService>::sync_echo(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = echoCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      echoImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback));
    });

  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_echo(returnState);
  });
}


folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyService>::future_echo() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_echo(rpcOptions);
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyService>::semifuture_echo() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_echo(rpcOptions);
}

folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyService>::future_echo(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_echo, channel_);
  echo(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyService>::semifuture_echo(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_echo, channel_);
  auto callback = std::move(callbackAndFuture.first);
  echo(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_future_echo(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_echo, channel_);
  echo(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_semifuture_echo(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_echo, channel_);
  auto callback = std::move(callbackAndFuture.first);
  echo(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::MyService>::echo(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  echo(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_wrapped_echo(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::MyService_echo_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::cpp2::MyService>::recv_echo(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_echo(state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::cpp2::MyService>::recv_instance_echo(::apache::thrift::ClientReceiveState& state) {
  recv_echo(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_instance_wrapped_echo(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_echo(state);
}

void apache::thrift::Client<::cpp2::MyService>::getRandomData(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  getRandomData(rpcOptions, std::move(callback), p_req);
}

void apache::thrift::Client<::cpp2::MyService>::getRandomData(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::cpp2::Request& p_req) {
  auto [ctx, header] = getRandomDataCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  getRandomDataImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_req);
}

void apache::thrift::Client<::cpp2::MyService>::getRandomDataImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::cpp2::Request& p_req, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        getRandomDataT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_req);
      } else {
        getRandomDataT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_req);
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        getRandomDataT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_req);
      } else {
        getRandomDataT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_req);
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::MyService>::getRandomDataCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      getServiceName(),
      "MyService.getRandomData",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::cpp2::MyService>::sync_getRandomData(::std::string& _return, const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_getRandomData(rpcOptions, _return, p_req);
}

void apache::thrift::Client<::cpp2::MyService>::sync_getRandomData(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return, const ::cpp2::Request& p_req) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = getRandomDataCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      getRandomDataImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_req);
    });

  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_getRandomData(_return, returnState);
  });
}


folly::Future<::std::string> apache::thrift::Client<::cpp2::MyService>::future_getRandomData(const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_getRandomData(rpcOptions, p_req);
}

folly::SemiFuture<::std::string> apache::thrift::Client<::cpp2::MyService>::semifuture_getRandomData(const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_getRandomData(rpcOptions, p_req);
}

folly::Future<::std::string> apache::thrift::Client<::cpp2::MyService>::future_getRandomData(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  folly::Promise<::std::string> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::string>>(std::move(promise), recv_wrapped_getRandomData, channel_);
  getRandomData(rpcOptions, std::move(callback), p_req);
  return future;
}

folly::SemiFuture<::std::string> apache::thrift::Client<::cpp2::MyService>::semifuture_getRandomData(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_getRandomData, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getRandomData(rpcOptions, std::move(callback), p_req);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_future_getRandomData(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  folly::Promise<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::std::string>>(std::move(promise), recv_wrapped_getRandomData, channel_);
  getRandomData(rpcOptions, std::move(callback), p_req);
  return future;
}

folly::SemiFuture<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_semifuture_getRandomData(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_getRandomData, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getRandomData(rpcOptions, std::move(callback), p_req);
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::MyService>::getRandomData(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::cpp2::Request& p_req) {
  getRandomData(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_req);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_wrapped_getRandomData(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::MyService_getRandomData_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::cpp2::MyService>::recv_getRandomData(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_getRandomData(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::cpp2::MyService>::recv_instance_getRandomData(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_getRandomData(_return, state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_instance_wrapped_getRandomData(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_getRandomData(_return, state);
}

void apache::thrift::Client<::cpp2::MyService>::getId(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_field) {
  ::apache::thrift::RpcOptions rpcOptions;
  getId(rpcOptions, std::move(callback), p_field);
}

void apache::thrift::Client<::cpp2::MyService>::getId(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_field) {
  auto [ctx, header] = getIdCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  getIdImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_field);
}

void apache::thrift::Client<::cpp2::MyService>::getIdImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_field, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        getIdT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_field);
      } else {
        getIdT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_field);
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        getIdT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_field);
      } else {
        getIdT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_field);
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::MyService>::getIdCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      getServiceName(),
      "MyService.getId",
      *header);

  return {std::move(ctx), std::move(header)};
}

::std::int32_t apache::thrift::Client<::cpp2::MyService>::sync_getId(::std::int32_t p_field) {
  ::apache::thrift::RpcOptions rpcOptions;
  return sync_getId(rpcOptions, p_field);
}

::std::int32_t apache::thrift::Client<::cpp2::MyService>::sync_getId(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_field) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = getIdCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      getIdImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_field);
    });

  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      return recv_getId(returnState);
  });
}


folly::Future<::std::int32_t> apache::thrift::Client<::cpp2::MyService>::future_getId(::std::int32_t p_field) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_getId(rpcOptions, p_field);
}

folly::SemiFuture<::std::int32_t> apache::thrift::Client<::cpp2::MyService>::semifuture_getId(::std::int32_t p_field) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_getId(rpcOptions, p_field);
}

folly::Future<::std::int32_t> apache::thrift::Client<::cpp2::MyService>::future_getId(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_field) {
  folly::Promise<::std::int32_t> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::int32_t>>(std::move(promise), recv_wrapped_getId, channel_);
  getId(rpcOptions, std::move(callback), p_field);
  return future;
}

folly::SemiFuture<::std::int32_t> apache::thrift::Client<::cpp2::MyService>::semifuture_getId(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_field) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_getId, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getId(rpcOptions, std::move(callback), p_field);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::std::int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_future_getId(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_field) {
  folly::Promise<std::pair<::std::int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::std::int32_t>>(std::move(promise), recv_wrapped_getId, channel_);
  getId(rpcOptions, std::move(callback), p_field);
  return future;
}

folly::SemiFuture<std::pair<::std::int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_semifuture_getId(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_field) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_getId, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getId(rpcOptions, std::move(callback), p_field);
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::MyService>::getId(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int32_t p_field) {
  getId(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_field);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_wrapped_getId(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::MyService_getId_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

::std::int32_t apache::thrift::Client<::cpp2::MyService>::recv_getId(::apache::thrift::ClientReceiveState& state) {
  ::std::int32_t _return;
  auto ew = recv_wrapped_getId(_return, state);
  if (ew) {
    ew.throw_exception();
  }
  return _return;
}

::std::int32_t apache::thrift::Client<::cpp2::MyService>::recv_instance_getId(::apache::thrift::ClientReceiveState& state) {
  return recv_getId(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_instance_wrapped_getId(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_getId(_return, state);
}

void apache::thrift::Client<::cpp2::MyService>::ping_eb(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  ping_eb(rpcOptions, std::move(callback), p_req);
}

void apache::thrift::Client<::cpp2::MyService>::ping_eb(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::cpp2::Request& p_req) {
  auto [ctx, header] = ping_ebCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  ping_ebImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_req);
}

void apache::thrift::Client<::cpp2::MyService>::ping_ebImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::cpp2::Request& p_req, bool stealRpcOptions) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      if (stealRpcOptions) {
        ping_ebT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_req);
      } else {
        ping_ebT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_req);
      }
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      if (stealRpcOptions) {
        ping_ebT(&writer, std::move(rpcOptions), std::move(header), contextStack, std::move(callback), p_req);
      } else {
        ping_ebT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback), p_req);
      }
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::MyService>::ping_ebCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      getServiceName(),
      "MyService.ping_eb",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::cpp2::MyService>::sync_ping_eb(const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_ping_eb(rpcOptions, p_req);
}

void apache::thrift::Client<::cpp2::MyService>::sync_ping_eb(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = ping_ebCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  callback.waitUntilDone(
    evb,
    [&] {
      ping_ebImpl(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_req);
    });

  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_ping_eb(returnState);
  });
}


folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyService>::future_ping_eb(const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_ping_eb(rpcOptions, p_req);
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyService>::semifuture_ping_eb(const ::cpp2::Request& p_req) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_ping_eb(rpcOptions, p_req);
}

folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyService>::future_ping_eb(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  folly::Promise<folly::Unit> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_ping_eb, channel_);
  ping_eb(rpcOptions, std::move(callback), p_req);
  return future;
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyService>::semifuture_ping_eb(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_ping_eb, channel_);
  auto callback = std::move(callbackAndFuture.first);
  ping_eb(rpcOptions, std::move(callback), p_req);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_future_ping_eb(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_ping_eb, channel_);
  ping_eb(rpcOptions, std::move(callback), p_req);
  return future;
}

folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> apache::thrift::Client<::cpp2::MyService>::header_semifuture_ping_eb(apache::thrift::RpcOptions& rpcOptions, const ::cpp2::Request& p_req) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_ping_eb, channel_);
  auto callback = std::move(callbackAndFuture.first);
  ping_eb(rpcOptions, std::move(callback), p_req);
  return std::move(callbackAndFuture.second);
}

void apache::thrift::Client<::cpp2::MyService>::ping_eb(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::cpp2::Request& p_req) {
  ping_eb(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_req);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_wrapped_ping_eb(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::MyService_ping_eb_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::cpp2::MyService>::recv_ping_eb(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_ping_eb(state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::cpp2::MyService>::recv_instance_ping_eb(::apache::thrift::ClientReceiveState& state) {
  recv_ping_eb(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::MyService>::recv_instance_wrapped_ping_eb(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_ping_eb(state);
}



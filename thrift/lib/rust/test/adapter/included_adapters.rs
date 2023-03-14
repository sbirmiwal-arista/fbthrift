/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// If you want an adapter to refer to a Thrift struct defined in the Thrift file using the adapter,
// you have to use `rust_include_srcs` to avoid the target circular dependency.
use fbthrift::adapter::ThriftAdapter;

use crate::types::AdaptedString;
use crate::types::Foo;
use crate::types::WrappedAdaptedBytes;

pub struct FieldCheckerAdapter {}

impl ThriftAdapter for FieldCheckerAdapter {
    type StandardType = String;
    type Error = anyhow::Error;

    type AdaptedType = String;

    fn from_thrift(value: Self::StandardType) -> Result<Self::AdaptedType, Self::Error> {
        Ok(value)
    }

    fn to_thrift(value: &Self::AdaptedType) -> Self::StandardType {
        value.clone()
    }

    fn from_thrift_field(
        value: Self::StandardType,
        field_id: i16,
        strct: std::any::TypeId,
    ) -> Result<Self::AdaptedType, Self::Error> {
        assert_eq!(field_id, 8);
        assert_eq!(std::any::TypeId::of::<Foo>(), strct);

        Self::from_thrift(value)
    }

    fn to_thrift_field(
        value: &Self::AdaptedType,
        field_id: i16,
        strct: std::any::TypeId,
    ) -> Self::StandardType {
        assert_eq!(field_id, 8);
        assert_eq!(std::any::TypeId::of::<Foo>(), strct);

        Self::to_thrift(value)
    }
}

pub struct IOBufIdentityAdapter {}

impl ThriftAdapter for IOBufIdentityAdapter {
    type StandardType = bytes::Bytes;
    type Error = std::convert::Infallible;

    type AdaptedType = bytes::Bytes;

    fn from_thrift(value: Self::StandardType) -> Result<Self::AdaptedType, Self::Error> {
        Ok(value)
    }

    fn to_thrift(value: &Self::AdaptedType) -> Self::StandardType {
        value.clone()
    }
}

pub struct WrappedAdaptedBytesIdentityAdapter {}

impl ThriftAdapter for WrappedAdaptedBytesIdentityAdapter {
    type StandardType = WrappedAdaptedBytes;
    type Error = std::convert::Infallible;

    type AdaptedType = WrappedAdaptedBytes;

    fn from_thrift(value: Self::StandardType) -> Result<Self::AdaptedType, Self::Error> {
        Ok(value)
    }

    fn to_thrift(value: &Self::AdaptedType) -> Self::StandardType {
        value.clone()
    }
}

pub struct AdaptedStringListIdentityAdapter {}

impl ThriftAdapter for AdaptedStringListIdentityAdapter {
    type StandardType = Vec<AdaptedString>;
    type Error = std::convert::Infallible;

    type AdaptedType = Vec<AdaptedString>;

    fn from_thrift(value: Self::StandardType) -> Result<Self::AdaptedType, Self::Error> {
        Ok(value)
    }

    fn to_thrift(value: &Self::AdaptedType) -> Self::StandardType {
        value.clone()
    }
}
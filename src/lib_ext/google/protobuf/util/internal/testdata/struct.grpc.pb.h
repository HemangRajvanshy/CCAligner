// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: google/protobuf/util/internal/testdata/struct.proto
// Original file comments:
// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Proto to test proto3 struct.
#ifndef GRPC_google_2fprotobuf_2futil_2finternal_2ftestdata_2fstruct_2eproto__INCLUDED
#define GRPC_google_2fprotobuf_2futil_2finternal_2ftestdata_2fstruct_2eproto__INCLUDED

#include "google/protobuf/util/internal/testdata/struct.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace google {
namespace protobuf {
namespace testing {
namespace structs {

class TestService GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Call(::grpc::ClientContext* context, const ::google::protobuf::testing::structs::StructType& request, ::google::protobuf::testing::structs::StructType* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::structs::StructType>> AsyncCall(::grpc::ClientContext* context, const ::google::protobuf::testing::structs::StructType& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::structs::StructType>>(AsyncCallRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::structs::StructType>* AsyncCallRaw(::grpc::ClientContext* context, const ::google::protobuf::testing::structs::StructType& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Call(::grpc::ClientContext* context, const ::google::protobuf::testing::structs::StructType& request, ::google::protobuf::testing::structs::StructType* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::structs::StructType>> AsyncCall(::grpc::ClientContext* context, const ::google::protobuf::testing::structs::StructType& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::structs::StructType>>(AsyncCallRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::structs::StructType>* AsyncCallRaw(::grpc::ClientContext* context, const ::google::protobuf::testing::structs::StructType& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_Call_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Call(::grpc::ServerContext* context, const ::google::protobuf::testing::structs::StructType* request, ::google::protobuf::testing::structs::StructType* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Call : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Call() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Call() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Call(::grpc::ServerContext* context, const ::google::protobuf::testing::structs::StructType* request, ::google::protobuf::testing::structs::StructType* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCall(::grpc::ServerContext* context, ::google::protobuf::testing::structs::StructType* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::testing::structs::StructType>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Call<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Call : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Call() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Call() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Call(::grpc::ServerContext* context, const ::google::protobuf::testing::structs::StructType* request, ::google::protobuf::testing::structs::StructType* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace structs
}  // namespace testing
}  // namespace protobuf
}  // namespace google


#endif  // GRPC_google_2fprotobuf_2futil_2finternal_2ftestdata_2fstruct_2eproto__INCLUDED

// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: google/protobuf/util/internal/testdata/maps.proto
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
// Proto to test proto3 maps.
#ifndef GRPC_google_2fprotobuf_2futil_2finternal_2ftestdata_2fmaps_2eproto__INCLUDED
#define GRPC_google_2fprotobuf_2futil_2finternal_2ftestdata_2fmaps_2eproto__INCLUDED

#include "google/protobuf/util/internal/testdata/maps.pb.h"

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
namespace maps {

class TestService GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Call1(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::google::protobuf::testing::maps::MapOut* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::maps::MapOut>> AsyncCall1(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::maps::MapOut>>(AsyncCall1Raw(context, request, cq));
    }
    virtual ::grpc::Status Call2(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::google::protobuf::testing::maps::MapOut* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::maps::MapOut>> AsyncCall2(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::maps::MapOut>>(AsyncCall2Raw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::maps::MapOut>* AsyncCall1Raw(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::testing::maps::MapOut>* AsyncCall2Raw(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Call1(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::google::protobuf::testing::maps::MapOut* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::maps::MapOut>> AsyncCall1(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::maps::MapOut>>(AsyncCall1Raw(context, request, cq));
    }
    ::grpc::Status Call2(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::google::protobuf::testing::maps::MapOut* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::maps::MapOut>> AsyncCall2(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::maps::MapOut>>(AsyncCall2Raw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::maps::MapOut>* AsyncCall1Raw(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::maps::MapOut>* AsyncCall2Raw(::grpc::ClientContext* context, const ::google::protobuf::testing::maps::MapIn& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_Call1_;
    const ::grpc::RpcMethod rpcmethod_Call2_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Call1(::grpc::ServerContext* context, const ::google::protobuf::testing::maps::MapIn* request, ::google::protobuf::testing::maps::MapOut* response);
    virtual ::grpc::Status Call2(::grpc::ServerContext* context, const ::google::protobuf::testing::maps::MapIn* request, ::google::protobuf::testing::maps::MapOut* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Call1 : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Call1() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Call1() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Call1(::grpc::ServerContext* context, const ::google::protobuf::testing::maps::MapIn* request, ::google::protobuf::testing::maps::MapOut* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCall1(::grpc::ServerContext* context, ::google::protobuf::testing::maps::MapIn* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::testing::maps::MapOut>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Call2 : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Call2() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_Call2() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Call2(::grpc::ServerContext* context, const ::google::protobuf::testing::maps::MapIn* request, ::google::protobuf::testing::maps::MapOut* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCall2(::grpc::ServerContext* context, ::google::protobuf::testing::maps::MapIn* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::testing::maps::MapOut>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Call1<WithAsyncMethod_Call2<Service > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Call1 : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Call1() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Call1() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Call1(::grpc::ServerContext* context, const ::google::protobuf::testing::maps::MapIn* request, ::google::protobuf::testing::maps::MapOut* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Call2 : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Call2() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_Call2() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Call2(::grpc::ServerContext* context, const ::google::protobuf::testing::maps::MapIn* request, ::google::protobuf::testing::maps::MapOut* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace maps
}  // namespace testing
}  // namespace protobuf
}  // namespace google


#endif  // GRPC_google_2fprotobuf_2futil_2finternal_2ftestdata_2fmaps_2eproto__INCLUDED

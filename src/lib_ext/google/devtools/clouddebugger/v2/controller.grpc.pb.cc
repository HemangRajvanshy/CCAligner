// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: google/devtools/clouddebugger/v2/controller.proto

#include "google/devtools/clouddebugger/v2/controller.pb.h"
#include "google/devtools/clouddebugger/v2/controller.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace google {
namespace devtools {
namespace clouddebugger {
namespace v2 {

static const char* Controller2_method_names[] = {
  "/google.devtools.clouddebugger.v2.Controller2/RegisterDebuggee",
  "/google.devtools.clouddebugger.v2.Controller2/ListActiveBreakpoints",
  "/google.devtools.clouddebugger.v2.Controller2/UpdateActiveBreakpoint",
};

std::unique_ptr< Controller2::Stub> Controller2::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< Controller2::Stub> stub(new Controller2::Stub(channel));
  return stub;
}

Controller2::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_RegisterDebuggee_(Controller2_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ListActiveBreakpoints_(Controller2_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_UpdateActiveBreakpoint_(Controller2_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Controller2::Stub::RegisterDebuggee(::grpc::ClientContext* context, const ::google::devtools::clouddebugger::v2::RegisterDebuggeeRequest& request, ::google::devtools::clouddebugger::v2::RegisterDebuggeeResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_RegisterDebuggee_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::devtools::clouddebugger::v2::RegisterDebuggeeResponse>* Controller2::Stub::AsyncRegisterDebuggeeRaw(::grpc::ClientContext* context, const ::google::devtools::clouddebugger::v2::RegisterDebuggeeRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::devtools::clouddebugger::v2::RegisterDebuggeeResponse>(channel_.get(), cq, rpcmethod_RegisterDebuggee_, context, request);
}

::grpc::Status Controller2::Stub::ListActiveBreakpoints(::grpc::ClientContext* context, const ::google::devtools::clouddebugger::v2::ListActiveBreakpointsRequest& request, ::google::devtools::clouddebugger::v2::ListActiveBreakpointsResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_ListActiveBreakpoints_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::devtools::clouddebugger::v2::ListActiveBreakpointsResponse>* Controller2::Stub::AsyncListActiveBreakpointsRaw(::grpc::ClientContext* context, const ::google::devtools::clouddebugger::v2::ListActiveBreakpointsRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::devtools::clouddebugger::v2::ListActiveBreakpointsResponse>(channel_.get(), cq, rpcmethod_ListActiveBreakpoints_, context, request);
}

::grpc::Status Controller2::Stub::UpdateActiveBreakpoint(::grpc::ClientContext* context, const ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointRequest& request, ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_UpdateActiveBreakpoint_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointResponse>* Controller2::Stub::AsyncUpdateActiveBreakpointRaw(::grpc::ClientContext* context, const ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointResponse>(channel_.get(), cq, rpcmethod_UpdateActiveBreakpoint_, context, request);
}

Controller2::Service::Service() {
  (void)Controller2_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      Controller2_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Controller2::Service, ::google::devtools::clouddebugger::v2::RegisterDebuggeeRequest, ::google::devtools::clouddebugger::v2::RegisterDebuggeeResponse>(
          std::mem_fn(&Controller2::Service::RegisterDebuggee), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Controller2_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Controller2::Service, ::google::devtools::clouddebugger::v2::ListActiveBreakpointsRequest, ::google::devtools::clouddebugger::v2::ListActiveBreakpointsResponse>(
          std::mem_fn(&Controller2::Service::ListActiveBreakpoints), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Controller2_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Controller2::Service, ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointRequest, ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointResponse>(
          std::mem_fn(&Controller2::Service::UpdateActiveBreakpoint), this)));
}

Controller2::Service::~Service() {
}

::grpc::Status Controller2::Service::RegisterDebuggee(::grpc::ServerContext* context, const ::google::devtools::clouddebugger::v2::RegisterDebuggeeRequest* request, ::google::devtools::clouddebugger::v2::RegisterDebuggeeResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Controller2::Service::ListActiveBreakpoints(::grpc::ServerContext* context, const ::google::devtools::clouddebugger::v2::ListActiveBreakpointsRequest* request, ::google::devtools::clouddebugger::v2::ListActiveBreakpointsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Controller2::Service::UpdateActiveBreakpoint(::grpc::ServerContext* context, const ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointRequest* request, ::google::devtools::clouddebugger::v2::UpdateActiveBreakpointResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace google
}  // namespace devtools
}  // namespace clouddebugger
}  // namespace v2


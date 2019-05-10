// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: actionHandler.proto
#ifndef GRPC_actionHandler_2eproto__INCLUDED
#define GRPC_actionHandler_2eproto__INCLUDED

#include "actionHandler.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

class inputHandler final {
 public:
  static constexpr char const* service_full_name() {
    return "inputHandler";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status getInput(::grpc::ClientContext* context, const ::Input& request, ::Frame* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Frame>> AsyncgetInput(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Frame>>(AsyncgetInputRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Frame>> PrepareAsyncgetInput(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Frame>>(PrepareAsyncgetInputRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void getInput(::grpc::ClientContext* context, const ::Input* request, ::Frame* response, std::function<void(::grpc::Status)>) = 0;
      virtual void getInput(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Frame* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Frame>* AsyncgetInputRaw(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Frame>* PrepareAsyncgetInputRaw(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status getInput(::grpc::ClientContext* context, const ::Input& request, ::Frame* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Frame>> AsyncgetInput(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Frame>>(AsyncgetInputRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Frame>> PrepareAsyncgetInput(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Frame>>(PrepareAsyncgetInputRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void getInput(::grpc::ClientContext* context, const ::Input* request, ::Frame* response, std::function<void(::grpc::Status)>) override;
      void getInput(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Frame* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::Frame>* AsyncgetInputRaw(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Frame>* PrepareAsyncgetInputRaw(::grpc::ClientContext* context, const ::Input& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_getInput_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_getInput : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_getInput() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_getInput() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetInput(::grpc::ServerContext* context, ::Input* request, ::grpc::ServerAsyncResponseWriter< ::Frame>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_getInput<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_getInput : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_getInput() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::Input, ::Frame>(
          [this](::grpc::ServerContext* context,
                 const ::Input* request,
                 ::Frame* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->getInput(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithCallbackMethod_getInput() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_getInput<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_getInput : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_getInput() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_getInput() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_getInput : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_getInput() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_getInput() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetInput(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_getInput : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_getInput() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->getInput(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_getInput() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void getInput(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_getInput : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_getInput() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::Input, ::Frame>(std::bind(&WithStreamedUnaryMethod_getInput<BaseClass>::StreamedgetInput, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_getInput() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status getInput(::grpc::ServerContext* context, const ::Input* request, ::Frame* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedgetInput(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Input,::Frame>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_getInput<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_getInput<Service > StreamedService;
};


#endif  // GRPC_actionHandler_2eproto__INCLUDED

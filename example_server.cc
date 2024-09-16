#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"
#include "example.pb.h"

class ProssessingImpl : public ProcessingServices::Service
{
  ::grpc::Status computeSum(::grpc::ServerContext *context, const ::Point3 *request, ::Numeric *response)
  {
    std::cout << "Hey" << std::endl;
    response->set_value(request->x() + request->y() + request->z());
    return grpc::Status::OK;
  }
};

int main()
{
  ProssessingImpl service;
  grpc::ServerBuilder builder;
  builder.AddListeningPort("0.0.0.0:9999", grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  server->Wait();

  return 0;
}
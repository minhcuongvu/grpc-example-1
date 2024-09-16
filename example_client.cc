#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"
#include "example.pb.h"

class ProcessingClient
{
public:
  ProcessingClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(ProcessingServices::NewStub(channel)) {}

  double ComputeSum(double x, double y, double z)
  {
    Point3 request;
    request.set_x(x);
    request.set_y(y);
    request.set_z(z);

    Numeric response;
    grpc::ClientContext context;

    grpc::Status status = stub_->computeSum(&context, request, &response);

    if (status.ok())
    {
      return response.value();
    }
    else
    {
      std::cout << "RPC failed: " << status.error_code() << ": " << status.error_message() << std::endl;
      return 0;
    }
  }

private:
  std::unique_ptr<ProcessingServices::Stub> stub_;
};

int main(int argc, char **argv)
{
  // Create a client
  ProcessingClient client(grpc::CreateChannel("localhost:9999", grpc::InsecureChannelCredentials()));

  // Test the ComputeSum RPC
  double x = 1.0, y = 2.0, z = 3.0;
  double result = client.ComputeSum(x, y, z);

  std::cout << "Sum of " << x << ", " << y << ", and " << z << " is: " << result << std::endl;

  return 0;
}
#include <network/server/incl/server.h>
#include <utils/input/input_manager.h>
#include <utils/logging/logging.h>
#include "main_globals.h"

int main(int argc, char* argv[]){
  InitLogger("ServerLogger");

  std::string server_address("127.0.0.1:4000");

  // create service implementation 
  // and server builder 
  InputManager service;
  GameServer server;
  ServerBuilder builder;

  // Add server info
  // and bind service
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  builder.RegisterService(&server);

  // start server
  std::unique_ptr<Server> grpcServer(builder.BuildAndStart());
  cout << "Server listening on " << server_address << std::endl;
  grpcServer->Wait();

  return 0;
}

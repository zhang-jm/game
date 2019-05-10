#include "server.h"

// TODO stubbed; JUZ
gameServer::gameServer() {
}



// TODO stubbed ; JUZ
void gameServer::open(){
  return;
}

// TODO stubbed ; JUZ
void gameServer::close(){
  return;
}

// TODO stubbed ; JUZ
void gameServer::init_maze(){
  return;
}

// TODO stubbed ; JUZ
void gameServer::init(){
  init_maze();
  return;
}

// build gRPC server
void gameServer::run_server(){
  std::string server_address("127.0.0.1:4000");

  // create service implementation 
  // and server builder 
  actionHandlerImpl service;
  ServerBuilder builder;

  // Add server info
  // and bind service
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  // start server
  std::unique_ptr<Server> server(builder.BuildAndStart());
  cout << "Server listening on " << server_address << std::endl;
  server->Wait();

  return;
}
// TODO stubbed ; JUZ
void gameServer::clean_up(){

}


// TODO stubbed ; JUZ
void gameServer::step(const float dt){
  return;
}
#include "server.h"

// TODO stubbed; JUZ
Server::Server(const uint16_t port, const size_t num_clients)
  {
    init();
  }



// TODO stubbed ; JUZ
void Server::open(){
  return;
}

// TODO stubbed ; JUZ
void Server::close(){
  return;
}

// TODO stubbed ; JUZ
void Server::init_maze(){
  return;
}

// TODO stubbed ; JUZ
void Server::init(){
  init_maze();
  return;
}

// TODO stubbed ; JUZ
// since this begins the server loop
// declared static to avoid creating instance
// of Server object in main loop
void Server::run_server(const uint16_t port, const size_t num_players){
  std::string server_address("127.0.0.1");
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  
  return;
}
// TODO stubbed ; JUZ
void Server::clean_up(){

}


// TODO stubbed ; JUZ
void Server::step(const float dt){
  return;
}
#include "server.h"




// TODO stubbed; JUZ
Server::Server(const uint16_t port, const size_t num_players)
  : game_started(true)
  , multiplayer_connection(port, num_players)
  {
    init();
  }



// Creates network
// waits for client connection
void Server::start(int num_players){

  // binds and listens on master socket
  // updates the socket descriptors
  if(!this->multiplayer_connection.multiplayer_network_setup()){
    perror(" Multiplayer network setup failed!\n");
  }

  // blocking call
  // wait for incoming connections
  if(!this->multiplayer_connection.multiplayer_connect()){
    perror(" Failed to connect to all players\n");
  }

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
  // Create server instance
  Server server(port, num_players);

  // Open connection and wait for players
  server.start(num_players);

  // Server loop
  while(true)
  {
    server.step(0.005);
  }
  return;
}
// TODO stubbed ; JUZ
void Server::clean_up(){

}

// TODO stubbed ; JUZ
void Server::step(const float dt){
  return;
}
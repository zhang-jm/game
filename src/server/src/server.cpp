#include "server.h"

Server::Server(const string ip_address, const uint16_t port, const size_t num_connections)
  : server_connection(ip_address, port, num_connections){
    init();
}

// Creates network
// waits for client connection
bool Server::establish_network(vector<int> &communication_sockets){

  // binds and listens on master socket
  // updates the socket descriptors
  printf("Setting up server network...\n");
  if(!this->server_connection.server_network_setup()){
    perror(" Multiplayer network setup failed!\n");
    return false;
  }
  else{
    // blocking call
    // wait for incoming connections
    if(!this->server_connection.server_connect(communication_sockets)){
      perror(" Failed to connect to all players\n");
      return false;
    }
  }

  return true;
}

// TODO stubbed ; JUZ
void Server::teardown_network(){
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

void Server::run_server(string ip_address, const uint16_t port,
                        const size_t num_connections){
  // Create server instance
  Server server(ip_address, port, num_connections);

  // Blocking call
  // Open connection and wait for players
  if(!server.establish_network(server.communication_sockets)){
      perror("Could not establish server network\n");
  }

  printf("Server network setup entering core server loop...\n");
  // Server loop
  while(true){
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
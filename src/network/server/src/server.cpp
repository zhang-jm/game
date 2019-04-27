#include "server.h"




// Constructor
// TODO not completed; JUZ
Server::Server(const uint16_t port, const size_t max_clients)
  : game_started(true)
  , port(port)
  , rpc_server(port)
  , max_clients(max_clients)

  {
    init();
  }



  // Begin player connections phase
void Server::Start(){
  rpc_server.async_run(max_clients);
  return;
}


// End of player connection phase
void Server::Close(){
  rpc_server.stop();
  return;
}

void init(){
  init_maze();
  return;
}


void init_maze(){
  return;
}


// TODO stubbed ; JUZ
void clean_up(){

}


// TODO stubbed ; JUZ
void Server::step(const float dt){
  return;
}
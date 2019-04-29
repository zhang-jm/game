#include "server.h"

#include "main_globals.h"

int main(int argc, char* argv[]){


  Server::run_server(IP_ADDRESS, SERVER_PORT, NUM_PLAYERS);
  return 0;
}

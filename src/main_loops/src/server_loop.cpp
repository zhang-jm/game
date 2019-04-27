#include "server.h"

#include "main_globals.h"

int main(int argc, char* argv[]){

  static int num_players = 4;
  Server::run_server(PORT, NUM_PLAYERS);
  return 0;
}

#include "client.h"

#include "main_globals.h"

int main(int argc, char* argv[]){

  Client::run_client(IP_ADDRESS, SERVER_PORT);
  return 0;
}
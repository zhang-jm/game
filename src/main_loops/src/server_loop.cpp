#include "server.h"

#include <utils/logging/logging.h>
#include "main_globals.h"

int main(int argc, char* argv[]){
  InitLogger("ServerLogger");

  gameServer::run_server();
  return 0;
}

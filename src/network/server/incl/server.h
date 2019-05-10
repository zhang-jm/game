#ifndef SERVER_H
#define SERVER_H


// TODO Move to a top level include
#define DEBUG_MAZE       1
#define LOGGING          1


/*---------------------------------
- SYSTEM INCLUDES
-----------------------------------*/

#include <stdlib.h> //size_t
#include <stdint.h>
#include <grpcpp/grpcpp.h>
#include "actionHandler.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using std::string;
using std::cout;
using std::endl;


// Service implementations
class actionHandlerImpl final : public inputHandler::Service {
  public:
    // Constructor
    explicit actionHandlerImpl(){

    }

    // Handle Player input 
    Status getInput(ServerContext * context, const Input * input,
                      Frame * response ) override {
      cout << "Received input : " << input->testinput() << endl;
      response->set_frame(2);
      return Status::OK;
    }
};



// Game Server
class gameServer {
  public:

    // Constructor
    gameServer();

    // Initialize game
    void init();

    // Create random maze
    void init_maze();

    // Begin player connections phase
    void open();

    // End of player connection phase
    void close();

    // stepping function
    void step(const float dt);

    // server loop
    static void run_server();
    /*-------------------------------
    - Debugging functions
    ---------------------------------*/

#if DEBUG_MAZE
    void debug_maze();
#endif
    // Clean up
    void clean_up();



  private:
    string              server_address;
    ServerBuilder       builder;
  
};


#endif
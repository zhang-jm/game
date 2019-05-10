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

class actionHandler final : public actionHandler::Service{
  Status getInput(ServerContext * context, const Input * input,
                      Frame * response ) override {
    response->set_name(GetFeatureName(*point, feature_list_));
    response->mutable_location()->CopyFrom(*point);
    return Status::OK;
  }
};
class Server {
  public:

    // Constructor
    Server(uint16_t port, size_t max_clients);

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
    static void run_server(const uint16_t port, const size_t num_players);
    /*-------------------------------
    - Debugging functions
    ---------------------------------*/

#if DEBUG_MAZE
    void debug_maze();
#endif
    // Clean up
    void clean_up();



  private:
    ServerBuilder builder;
};


#endif
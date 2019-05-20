#ifndef SERVER_H
#define SERVER_H


// TODO Move to a top level include
#define DEBUG_MAZE       1
#define LOGGING          1


/*---------------------------------
- SYSTEM INCLUDES
-----------------------------------*/

#include <map>
#include <stdlib.h> //size_t
#include <stdint.h>
#include <grpcpp/grpcpp.h>
#include <protos/object_handler.grpc.pb.h>
#include <network/server/incl/server_player.h>

using grpc::Server;
using grpc::ServerBuilder;
using std::string;
using std::cout;
using std::endl;

#define MAX_PLAYERS 4

// Game Server
class GameServer final : public ObjectHandler::Service {
  public:

    // Constructor
    GameServer();

    // Initialize game
    void init();

    // Create random maze
    void init_maze();

    grpc::Status initPlayer(grpc::ServerContext * context, const PlayerParams * input,
        PlayerInfo * response) override;

    grpc::Status getPlayers(grpc::ServerContext * context, const PlayerParams * input,
        Players * response) override;

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
    int current_player_id;
    string              server_address;
    ServerBuilder       builder;

    std::map<int, ServerPlayer *> player_map;
  
};

#endif
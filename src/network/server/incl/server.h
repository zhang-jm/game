#ifndef SERVER_H
#define SERVER_H


// TODO Move to a top level include
#define DEBUG_MAZE       1
#define LOGGING          1


#include "peer.h"



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

    /*-------------------------------
    - Debugging functions
    ---------------------------------*/

#ifdef DEBUG_MAZE
    void debug_maze();
#endif
    /*-------------------------------
    - Logging functions
    ---------------------------------*/
#ifdef LOGGING
    void server_log();
#endif
    // Clean up
    void clean_up();



  private:
    bool          game_started;
    uint16_t      port;
    Maze*         maze;

};


#endif
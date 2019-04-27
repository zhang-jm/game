#ifndef SERVER_H
#define SERVER_H


// TODO Move to a top level include
#define DEBUG_MAZE       1
#define LOGGING          1


/*---------------------------------
- SYSTEM INCLUDES
-----------------------------------*/

#include<stdlib.h> //size_t

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
    /*-------------------------------
    - Logging functions
    ---------------------------------*/
#if LOGGING
    void server_log();
#endif
    // Clean up
    void clean_up();



  private:
    bool          game_started;
    uint16_t      port;
    size_t        num_clients;

};


#endif
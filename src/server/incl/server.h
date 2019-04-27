#ifndef SERVER_H
#define SERVER_H

/*---------------------------------
- SYSTEM INCLUDES
-----------------------------------*/

#include<stdlib.h> //size_t
#include<stdio.h>
#include<errno.h>

/*---------------------------------
- Prototypes
-----------------------------------*/
#include "connect.h"

class Server {
  public:

    // Constructor
    Server(uint16_t port, size_t max_clients);

    // Initialize game
    void init();

    // Create random maze
    void init_maze();

    // Begin player connections phase
    void start(int num_players);

    // End of player connection phase
    void close();

    // stepping function
    void step(const float dt);

    // server loop
    static void run_server(const uint16_t port, const size_t num_players);

    /*-------------------------------
    - Debugging functions
    ---------------------------------*/

    void debug_maze();

    /*-------------------------------
    - Logging functions
    ---------------------------------*/

    void server_log();

    // Clean up
    void clean_up();



  private:
    bool                      game_started;
    Connection                multiplayer_connection;

};


#endif
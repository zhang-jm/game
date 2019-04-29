#ifndef SERVER_H
#define SERVER_H

/*---------------------------------
- SYSTEM INCLUDES
-----------------------------------*/

#include<stdlib.h> //size_t
#include<stdio.h>
#include<errno.h>
#include <string.h> //strcpy

/*---------------------------------
- Prototypes
-----------------------------------*/
#include "connect.h"

class Server {
  public:

    // Constructor
    Server(const string ip_address, const uint16_t port, size_t num_connections);

    // Initialize game
    void init();

    // Create random maze
    void init_maze();

    // Begin player connections phase
    bool establish_network(vector<int> &communication_sockets);

    // Gracefully end connections
    void teardown_network();

    // step function
    void step(const float dt);

    // server core loop
    static void run_server(string ip_address, const uint16_t port,
                                              const size_t num_connections);

    // process msg from player
    void process_msg();

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
    Communication_Buffer      data;
    Connection                server_connection;
    vector<int>               communication_sockets;


};


#endif
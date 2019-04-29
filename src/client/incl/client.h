#include "connect.h"

class Client{
  public:

    // Constructor
    Client(const string ip_address, const uint16_t port,
            size_t num_connections);

    // Begin connection phase
    void establish_network();

    // Gracefully close connection
    void teardown_network();

    // client core loop
    static void run_client(string ip_address, const uint16_t port);

    // process msg from server
    void process_msg();

    // Take a step
    void step(const float dt);

  private:
    Connection                client_connection;
    Communication_Buffer      data;
    int                       communication_socket;

};
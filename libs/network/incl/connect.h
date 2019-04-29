#ifndef CONNECT_H
#define CONNECT_H



/*---------------------------------
- SYSTEM INCLUDES
-----------------------------------*/

#ifdef _WIN32
#include<WinSock2.h>
#include<WS2tcpip.h>
#else
#include<sys/socket.h>
#include<arpa/inet.h> //inet addr inet_pton
#include<sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include<netinet/in.h>
#include<unistd.h> // usleep
#endif

#include<errno.h>
#include <string>
#include<vector>

/*---------------------------------
- Namespaces
-----------------------------------*/
using std::string;
using std::vector;
using std::max;

#define PACKET_SIZE 512

enum connection_state {
  DISCONNECTED,
  CONNECTED,
  CONNECTING,
  RECONNECTING
};

struct Packet{
  uint32_t length;
  char data[PACKET_SIZE];
};

struct Communication_Buffer{
  Packet     player_stream;
  Packet     server_stream;
};
class Connection{
  public:

    Connection(string ip_address, uint16_t port, size_t num_connections);

    ~Connection();

    // Creates master socket binds and listens
    bool server_network_setup();

    // Waits for incoming connections
    bool server_connect(vector<int> &communication_sockets);

    // creates socket, sets up addr info
    bool client_network_setup(int &communication_socket);

    bool client_connect(int &communication_socket);

    bool reconnect();

    bool disconnect();

    bool send_packet(const int socket, const Packet& packet);

    bool receive_packet(const int socket, const Packet& packet);

    connection_state state;

  private:

    string                ip_address;
    uint16_t              port;
    size_t                num_connections;
    int                   num_connected;
    int                   master_socket;
    sockaddr_in           addr;
    fd_set                readfds;
};
#endif



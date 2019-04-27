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
#include<arpa/inet.h> //inet addr
#include<sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#endif

/*---------------------------------
- Namespaces
-----------------------------------*/
using std::string;
using std::vector;


#define PACKET_SIZE 512

enum connection_state {
  DISCONNECTED,
  CONNECTED,
  CONNECTING,
  RECONNECTING
};

struct Send_Packet{
  uint32_t length;
  char data[PACKET_SIZE]
};


struct Receive_Packet{
  uint32_t length;
  char data[512];
};

class Mulitplayer_Connection{
  public:

    Connenction(uint16_t port, size_t num_players);

    ~Conenction();

    bool server_network_setup(const string ip_address);

    bool server_connect(const string ip_address,const uint16_t port);

    bool client_network_setup(const string ip_address);

    bool client_connect(const string ip_address,const uint16_t port);

    bool reconnect();

    bool disconnect();

    bool send_packet(const Send_Packet& packet);

    bool receive_packet(const Receive_Packet& packet);

    connection_state state;

  private:

    string        ip_address;
    uint16_t      port;
    size_t        num_players;
    int           num_players_connected;
    int           master_socket;
    vector<int>   player_sockets;
    sockaddr_in   player_addr;
    sockaddr_in   server_addr;
    fd_set        readfds;



};



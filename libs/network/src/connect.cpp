/*---------------------------------
- Prototypes
-----------------------------------*/
#include "connect.h"

Connection::Connection(const string ip_address,
                       const uint16_t port,
                       size_t num_connections)
  : state(DISCONNECTED),
    ip_address(ip_address),
    port(port),
    num_connections(num_connections),
    master_socket(-1) {

}

Connection::~Connection(){
  disconnect();
}

bool Connection::server_network_setup(){
  int             opt = true;
  int             i;

  // init master socket
  if( (this->master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) {
    perror(" Socket init failed \n");
    return false;
  }

  // set sock options
  if( setsockopt(this->master_socket, SOL_SOCKET, SO_REUSEADDR,
                (char *)&opt, sizeof(opt)) < 0){
    perror(" Socket options failed \n");
    return false;
  }

  // specify port, ip address, and type
  this->addr.sin_family = AF_INET;
  inet_pton(AF_INET, this->ip_address.c_str(), &(this->addr).sin_addr);
  this->addr.sin_port = htons( this->port );

  //bind
  if( bind(this->master_socket, (struct sockaddr *) &(this->addr), sizeof(this->addr)) < 0){
    perror("bind failed\n");
    return false;
  }

  // specify number of pending connections
  if( listen(this->master_socket, num_connections) < 0){
    printf("error listening:    \n"
           "master_socket     %d\n"
           "num_connections   %d\n", this->master_socket, num_connections);
    return false;
  }

  // finished setup, start listening on port
  return true;
}

bool Connection::server_connect(vector<int> &communication_sockets){
  int max_sd, active_fd, accept_socket, addrlen, i;
  Packet acceptance_packet;
  acceptance_packet.length = 40;
  strcpy(acceptance_packet.data, "Welcome to v bad multiplayer\n");

  // Initialize socket fd for num connections
  for(i = 0; i < this->num_connections; i++){
    communication_sockets.push_back(0);
  }

  addrlen = sizeof(this->addr);

  // wait for incoming connections
  while(true){
    // clear sockets
    FD_ZERO(&(this->readfds));

    // add master socket to set
    FD_SET(this->master_socket, &(this->readfds));

    // init max fd number
    max_sd = this->master_socket;

    for(auto communication_socket : communication_sockets){
      if(communication_socket){
        FD_SET( communication_socket, &(this->readfds) );
      }
      // needed for select function
      max_sd = max(this->master_socket, communication_socket);
    }

    // continuously wait for sockets to become available
    active_fd = select(max_sd + 1, &readfds, NULL, NULL, NULL);

    if( (active_fd < 0) && (errno != EINTR)){
      printf("select error");
      return false;
    }

    // Incoming connection
    if(FD_ISSET(this->master_socket, &(this->readfds))){
      if((accept_socket = accept(this->master_socket,
            (struct sockaddr *) &(this->addr), (socklen_t*)& addrlen)) < 0){
              perror("error player connection\n");
              return false;
      }
      // assign new incoming connection
      for(auto communication_socket : communication_sockets){
        if(!communication_socket){
          communication_socket = accept_socket;
          this->num_connected++;
          puts("Connected to player!\n");
          if(send(communication_socket, (char *) &acceptance_packet, acceptance_packet.length, 0)
                  !=  acceptance_packet.length){
            printf("Couldn't send acceptance message\n");
          }
          break;
        }
      }
      if(this->num_connected >= this->num_connections){
        puts("Finished connection phase!\n");
        this->state = CONNECTED;
        break;
      }
    }

  }
  return true;
}

bool Connection::client_network_setup(int & communication_socket){

  // create socket
  if((communication_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    printf("Socket creation error \n");
    close(communication_socket);
    return false;
  }

  // clear addr
  memset(&(this->addr), '0', sizeof(this->addr));
  this->addr.sin_family = AF_INET;
  this->addr.sin_port = htons(port);

  // Place ip address
  if(inet_pton(AF_INET, this->ip_address.c_str(), &(this->addr).sin_addr) <= 0){
    printf("Invalid address\n");
    close(communication_socket);
    return false;
  }
  return true;
}

bool Connection::client_connect(int &communication_socket){

  if(connect(communication_socket,(struct sockaddr *)&(this->addr),
                                   sizeof(this->addr)) < 0){
    perror("Connection failed:\n");
    close(communication_socket);
    return false;
  }
  printf("Connected to server\n");
  this->state=CONNECTED;
  return true;
}

bool Connection::reconnect(){
  return false;
}

bool Connection::disconnect(){
  return false;
}

// send a packet
bool Connection::send_packet(int socket, const Packet& packet){
  uint32_t num_bytes;

  num_bytes = (uint32_t) send(socket, (char *) &packet.data, packet.length, 0);
  if(num_bytes < packet.length){
    perror("bad send to client\n");
    return false;
  }
  return num_bytes == packet.length;
}

// receive packet
bool Connection::receive_packet(int socket, const Packet& packet){

  uint32_t num_bytes;
  uint32_t bytes_remaining;
  char recv_size[PACKET_SIZE];
  char buffer[PACKET_SIZE];

  // get msg size
  num_bytes = (uint32_t) recv(socket, recv_size, sizeof(packet.length), 0);

  memcpy((void *) &packet.length, (void *) recv_size, sizeof(packet.length));

  if(num_bytes == 0){
    perror("receive length error\n");
    return false;
  }
  else if(num_bytes != sizeof(packet.length)){
    this->state = DISCONNECTED;
    return false;
  }
  else{
    bytes_remaining = packet.length - num_bytes;
    num_bytes = 0;

    // Make sure we receive all bytes
    while(num_bytes != packet.length){
      num_bytes = (uint32_t) recv(socket, &buffer[sizeof(packet.length)],
                                  bytes_remaining, 0);
    }
  }

  // copy the data to our buffer
  memcpy((void *) packet.data, (void *) buffer, packet.length);
  return true;
}





Connenction(uint16_t port, size_t num_players)
  : state(DISCONNECTED),
    ip_address(""),
    port(port),
    num_players(num_players),
    master_socket(-1) {

}



~Conenction(){
  disconnect();
}

bool server_network_setup(const string ip_address,
                               const uint16_t port){
  int             opt = true;

  // set of socket descriptors
  fd_set          readfds;

  for(auto player_socket : this->player_sockets){
    player_socket = 0;
  }

  // init master socket
  if( (this->master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) {
    perror(" Socket init failed \n");
    exit(EXIT_FAILURE);
  }

  // set sock options
  if( setsockopt(this->master_socket, SOL_SOCKET, SO_REUSEADDR,
                (char *)&opt, sizeof(opt)) < 0){

    perror(" Socket options failed \n");
    exit(EXIT_FAILURE);
  }

  // specify port, ip, and type
  this->address.sin_family = AF_INET;
  this->address.sin_addr.s_addr = INADDR_ANY;
  this->address.sin_port = htons( this->port );

  //bind
  if( bind(this->master_socket, (struct sockaddr *) &address, sizeof(address)) < 0){
    perror("bind failed\n");
    exit(EXIT_FAILURE);
  }

  // specify number of pending connections
  if( listen(this->master_socket, num_players) < 0){
    perror("listen\n");
    exit(EXIT_FAILURE);
  }
  return;
}

bool server_connect(const string ip_address,const uint16_t port){
  int max_sd;
  char *message = "Welcome to shitty multiplayer experience\n";

  // wait for incoming connections
  while(true){
    // clear sockets
    FD_ZERO(&readfds);

    // add master socket to set
    FD_SET(master_socket, &readfds);

    // init max fd number
    max_sd = master_socket;

    for(auto player_socket : this->player_sockets){
      if(player_socket){
        FD_SET( player_socket, &readfds );
      }
      // needed for select function
      max_sd = max(master_socket, player_socket);
    }

    // continuously wait for sockets to become available
    active_fd = select(max_sd + 1, &readfds, NULL, NULL, NULL);

    if( (active_fd < 0) && (errno != EINTR)){
      printf("select error");
      return false;
    }

    // Incoming connection
    if(FD_ISSET(master_socket, &readfds)){
      if((accept_socket = accept(master_socket,
            (struct sockaddr *) &address, (socklen_t*)& addrlen)) < 0){
              perror("error player connection\n");
              return false;
      }
      // dump info
      if( send(accept_socket, acceptance_msg, strlen(acceptance_msg), 0)
          != strlen(message) ){
            perror("send");
            return false;
      }
      // assign new incoming connection
      for(auto player_socket : player_sockets){
        if(!player_socket){
          player_socket = accept_socket;
          this->num_players_connected++;
          break;
        }
      }
      if(num_players_connected >= this->num_players){
        puts("Finished connection phase!\n");
        this->state = CONNECTED;
        break;
      }
    }
  }
  return true;
}

bool client_network_setup(const string ip_address){
  return false;
}

bool client_connect(const string ip_address, const uint16_t port){
  return false;
}

bool reconnect(){
  return false;
}

bool disconnect(){
  return false;
}

bool send_packet(const Send_Packet& packet){
  return false;
}

bool receive_packet(const Receive_Packet& packet){
  return false;
}
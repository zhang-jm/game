#include "client.h"

// 1 is client case where we only have
// one socket fd
Client::Client(const string ip_address, const uint16_t port,
               size_t num_connections)
  : client_connection(ip_address, port, num_connections){
  return;
}

void Client::establish_network(){
  bool is_setup = false;
  // binds and listens on socket
  printf("Setting up client network...\n");
  while(!is_setup){
    printf("setting up \n");
    if(!this->client_connection.client_network_setup(this->communication_socket)){
      perror(" Client network setup failed!\n");
      close(this->communication_socket);
    }
    else{
      // blocking call
      // wait to connect to server
      printf("Connecting...\n");
      if(!this->client_connection.client_connect(this->communication_socket)){
        perror(" Failed to connect to server\n");
        printf(" Reconnecting...\n");
        usleep(5000);
      }
      else{
        is_setup = true;
      }
    }
  }
  return;
}

// TODO stubbed; juz
void Client::teardown_network(){
  return;
}

// TODO stubbed; juz
void Client::step(const float dt){
  return;
}

// TODO stubbed; juz
void Client::process_msg(){
  return;
}

void Client::run_client(string ip_address, const uint16_t port){

  // Create client network object
  Client client(ip_address, port, 1);

  // Blocking call
  // Open connection and wait to connect
  // to server
  client.establish_network();

  // take a step
  while(true){
    client.step(0.005);
  }

  return;
}
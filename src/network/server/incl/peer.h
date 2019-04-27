#ifndef PEER_H
#define PEER_H


class Peer{


  public:

    // Constructor
    Peer(Server & server)
      : server(server) {}

  private:
    Server& server;


};


#endif


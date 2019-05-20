#include "server.h"

#include <utils/input/input_manager.h>

// TODO stubbed; JUZ
GameServer::GameServer()
  : current_player_id(0) {
}

// TODO stubbed ; JUZ
void GameServer::open(){
  return;
}

// TODO stubbed ; JUZ
void GameServer::close(){
  return;
}

// TODO stubbed ; JUZ
void GameServer::init_maze(){
  return;
}

grpc::Status GameServer::initPlayer(grpc::ServerContext * context, const PlayerParams * input,
    PlayerInfo * response) {
    if (current_player_id >= MAX_PLAYERS) {
        return grpc::Status(grpc::FAILED_PRECONDITION, "Max number of players reached");
    }

    LOG.debug("Initializing player with ID {}", current_player_id);

    ServerPlayer * new_player = new ServerPlayer(current_player_id);

    response->set_id(new_player->GetID());
    response->set_health(new_player->GetHealth());
    /*Point * p = new Point();
    p->set_x(new_player->GetPosition().x);
    p->set_y(new_player->GetPosition().y);
    p->set_z(new_player->GetPosition().z);*/
    response->mutable_position()->set_x(new_player->GetPosition().x);
    response->mutable_position()->set_y(new_player->GetPosition().y);
    response->mutable_position()->set_z(new_player->GetPosition().z);

    player_map.insert({ current_player_id, new_player });
    current_player_id++;

    return grpc::Status::OK;
}

grpc::Status GameServer::getPlayers(grpc::ServerContext * context, const PlayerParams * input,
    Players * response) {
    return grpc::Status::OK;
}

// TODO stubbed ; JUZ
void GameServer::init(){
  init_maze();
  return;
}

// build gRPC server
void GameServer::run_server(){

  return;
}
// TODO stubbed ; JUZ
void GameServer::clean_up(){

}


// TODO stubbed ; JUZ
void GameServer::step(const float dt){
  return;
}
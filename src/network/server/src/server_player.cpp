#include <network/server/incl/server_player.h>

ServerPlayer::ServerPlayer(int id) 
    : player_id(id), 
      position(0.0f, 0.0f, 0.0f),
      health(100) { }

ServerPlayer::~ServerPlayer() { }

int ServerPlayer::GetID() { 
    return this->player_id;
}

glm::vec3 ServerPlayer::GetPosition() {
    return this->position;
}

void ServerPlayer::SetPosition(float x, float y, float z) {
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;
}

float ServerPlayer::GetHealth() {
    return this->health;
}

void ServerPlayer::SetHealth(float health) {
    this->health = health;
}

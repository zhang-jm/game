#ifndef __SERVER_PLAYER_H
#define __SERVER_PLAYER_H

#include <glm/vec3.hpp>

class ServerPlayer {
public:
    ServerPlayer(int id);
    ~ServerPlayer();

    int GetID();

    glm::vec3 GetPosition();
    void SetPosition(float x, float y, float z);

    float GetHealth();
    void SetHealth(float health);

private:
    int player_id;
    glm::vec3 position;
    float health;
};

#endif
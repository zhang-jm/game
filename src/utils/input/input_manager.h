#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <map>
#include <array>

#define NUMKEYS 350

enum Keys {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};

class InputManager {
public:
    InputManager();
    ~InputManager();

    void initDefaultKeys();

    void setKeyPressed(int keyID);
    void setKeyReleased(int keyID);

private:
    std::map<Keys, int> keyMap;
    std::array<bool, NUMKEYS> keyPressed{};
};

#endif
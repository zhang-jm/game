#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <map>
#include <array>

#include <grpcpp/grpcpp.h>
#include <protos/input_handler.grpc.pb.h>
#include <utils/logging/logging.h>

#define NUMKEYS 350

enum Keys {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};


class InputManager final : public InputHandler::Service {
public:
    explicit InputManager();
    ~InputManager();

    void initDefaultKeys();

    void setKeyPressed(int keyID);
    void setKeyReleased(int keyID);

    // Handle Player input 
    grpc::Status sendInput(grpc::ServerContext * context, const Input * input,
        InputResponse * response) override;

private:
    std::map<Keys, int> keyMap;
    std::array<bool, NUMKEYS> keyPressed{};
};

#endif
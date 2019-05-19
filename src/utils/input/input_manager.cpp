#include "input_manager.h"

#include <glfw/glfw3.h>
#include <utils/logging/logging.h>

InputManager::InputManager() {
    initDefaultKeys();
}

InputManager::~InputManager() {

}

void InputManager::initDefaultKeys() {

    //set default keys
    keyMap.insert({ MOVE_UP, GLFW_KEY_UP });
    keyMap.insert({ MOVE_DOWN, GLFW_KEY_DOWN });
    keyMap.insert({ MOVE_LEFT, GLFW_KEY_LEFT });
    keyMap.insert({ MOVE_RIGHT, GLFW_KEY_RIGHT });
}

void InputManager::setKeyPressed(int keyID) {
    keyPressed.at(keyID) = true;
}

void InputManager::setKeyReleased(int keyID) {
    keyPressed.at(keyID) = false;
}

grpc::Status InputManager::sendInput(grpc::ServerContext * context, const Input * input,
    InputResponse * response) {
    LOG.debug("Received input : {} {}", input->inputkey(), input->action());

    if (input->inputkey() >= NUMKEYS) {
        return grpc::Status(grpc::INVALID_ARGUMENT, "Input key value too large");
    }

    switch (input->action()) {
      case Input::InputAction::Input_InputAction_KEY_PRESS:
          setKeyPressed(input->inputkey());
          break;

      case Input::InputAction::Input_InputAction_KEY_RELEASE:
          setKeyReleased(input->inputkey());
          break;

      default:
          break;
    }

    return grpc::Status::OK;
}
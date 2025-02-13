#include "InputManager.hpp"

void InputManager::bindKey(sf::Keyboard::Key key, InputAction action) {
    mKeyBindings[key] = action;
}

void InputManager::bindAction(InputAction action, ActionCallback callback) {
    mActionCallbacks[action] = callback;
}

void InputManager::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        auto it = mKeyBindings.find(event.key.code);
        if (it != mKeyBindings.end()) {
            InputAction action = it->second;
            if (mActionCallbacks.find(action) != mActionCallbacks.end()) {
                mActionCallbacks[action]();
            }
        }
    }
}

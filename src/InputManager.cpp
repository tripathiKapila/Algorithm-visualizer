#include "InputManager.hpp"

void InputManager::bindKey(sf::Keyboard::Key key, InputAction action) {
    mKeyBindings[key] = action;
}

void InputManager::bindAction(InputAction action, std::function<void()> callback) {
    mActionCallbacks[action] = callback;
}

void InputManager::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        auto it = mKeyBindings.find(event.key.code);
        if (it != mKeyBindings.end()) {
            auto callbackIt = mActionCallbacks.find(it->second);
            if (callbackIt != mActionCallbacks.end()) {
                callbackIt->second();
            }
        }
    }
    
    // Also check for held keys for continuous speed adjustment
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        auto it = mActionCallbacks.find(InputAction::SpeedUp);
        if (it != mActionCallbacks.end()) {
            it->second();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        auto it = mActionCallbacks.find(InputAction::SpeedDown);
        if (it != mActionCallbacks.end()) {
            it->second();
        }
    }
} 
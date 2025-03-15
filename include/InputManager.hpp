#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <functional>

enum class InputAction {
    PlayPauseToggle,
    Step,
    SpeedUp,
    SpeedDown
};

class InputManager {
public:
    void bindKey(sf::Keyboard::Key key, InputAction action);
    void bindAction(InputAction action, std::function<void()> callback);
    void processEvent(const sf::Event& event);

private:
    std::map<sf::Keyboard::Key, InputAction> mKeyBindings;
    std::map<InputAction, std::function<void()>> mActionCallbacks;
};

#endif // INPUT_MANAGER_HPP 
#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <SFML/Window.hpp>
#include <functional>
#include <unordered_map>

enum class InputAction {
    PlayPauseToggle,
    Step,
    Save,
    Load,
    Reset,
    SpeedUp,
    SpeedDown,
    Rewind,       // New action
    FastForward   // New action
};

class InputManager {
public:
    using ActionCallback = std::function<void()>;
    void bindKey(sf::Keyboard::Key key, InputAction action);
    void bindAction(InputAction action, ActionCallback callback);
    void processEvent(const sf::Event& event);
private:
    std::unordered_map<sf::Keyboard::Key, InputAction> mKeyBindings;
    std::unordered_map<InputAction, ActionCallback> mActionCallbacks;
};

#endif // INPUT_MANAGER_HPP

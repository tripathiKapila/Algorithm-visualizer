#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Button.hpp"

class UIManager {
public:
    UIManager();
    void addButton(std::shared_ptr<Button> button);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
private:
    std::vector<std::shared_ptr<Button>> mButtons;
};

#endif // UI_MANAGER_HPP 
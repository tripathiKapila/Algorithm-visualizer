#include "UIManager.hpp"

UIManager::UIManager() {}

void UIManager::addButton(std::shared_ptr<Button> button) {
    mButtons.push_back(button);
}

void UIManager::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    for (auto& button : mButtons) {
        button->update(event, window);
    }
}

void UIManager::render(sf::RenderWindow& window) {
    for (auto& button : mButtons) {
        button->render(window);
    }
} 
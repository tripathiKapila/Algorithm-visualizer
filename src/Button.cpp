#include "Button.hpp"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position,
               const sf::Font& font, const std::string& textString, unsigned int characterSize) {
    mShape.setSize(size);
    mShape.setPosition(position);
    mShape.setFillColor(sf::Color(46, 204, 113));
    mShape.setOutlineThickness(2.f);
    mShape.setOutlineColor(sf::Color::White);
    
    mText.setFont(font);
    mText.setCharacterSize(characterSize);
    mText.setFillColor(sf::Color::White);
    
    // Set the text using our setText method which handles positioning
    setText(textString);
}

void Button::render(sf::RenderWindow& window) {
    window.draw(mShape);
    window.draw(mText);
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (mShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !mTooltip.empty()) {
        sf::Text tooltipText;
        tooltipText.setFont(*mText.getFont());
        tooltipText.setString(mTooltip);
        tooltipText.setCharacterSize(14);
        tooltipText.setFillColor(sf::Color::Yellow);
        tooltipText.setPosition(static_cast<float>(mousePos.x) + 10, static_cast<float>(mousePos.y) + 10);
        window.draw(tooltipText);
    }
}

bool Button::isClicked(const sf::Vector2f& mousePos) const {
    return mShape.getGlobalBounds().contains(mousePos);
}

void Button::setCallback(const std::function<void()>& callback) {
    mCallback = callback;
}

void Button::update(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
        if (isClicked(mousePos) && mCallback) {
            mCallback();
        }
    }
}

void Button::setPosition(const sf::Vector2f& position) {
    mShape.setPosition(position);
    sf::Vector2f size = mShape.getSize();
    mText.setPosition(position + size / 2.f);
}

void Button::setSize(const sf::Vector2f& size) {
    mShape.setSize(size);
    sf::Vector2f position = mShape.getPosition();
    mText.setPosition(position + size / 2.f);
}

void Button::setText(const std::string& text) {
    mText.setString(text);
    
    // Get the button dimensions and position
    sf::Vector2f buttonSize = mShape.getSize();
    sf::Vector2f buttonPos = mShape.getPosition();
    
    // Get text bounds
    sf::FloatRect textBounds = mText.getLocalBounds();
    
    // Set the origin to the center of the text bounds
    mText.setOrigin(textBounds.left + textBounds.width / 2.0f,
                    textBounds.top + textBounds.height / 2.0f);
    
    // Position text at the center of the button
    mText.setPosition(buttonPos.x + buttonSize.x / 2.0f,
                     buttonPos.y + buttonSize.y / 2.0f);
}

void Button::setTooltip(const std::string& tooltipText) {
    mTooltip = tooltipText;
} 
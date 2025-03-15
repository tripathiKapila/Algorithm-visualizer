#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

class Button {
public:
    Button(const sf::Vector2f& size, const sf::Vector2f& position,
           const sf::Font& font, const std::string& textString, unsigned int characterSize = 18);
    void render(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2f& mousePos) const;
    void setCallback(const std::function<void()>& callback);
    void update(const sf::Event& event, const sf::RenderWindow& window);
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);
    void setText(const std::string& textString);
    void setTooltip(const std::string& tooltipText);  // New method
private:
    sf::RectangleShape mShape;
    sf::Text mText;
    std::function<void()> mCallback;
    std::string mTooltip;
};

#endif // BUTTON_HPP 
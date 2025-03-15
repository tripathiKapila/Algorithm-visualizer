#ifndef THEME_MANAGER_HPP
#define THEME_MANAGER_HPP

#include <SFML/Graphics.hpp>

class ThemeManager {
public:
    enum class Theme {
        Dark,
        Light,
        Custom
    };

    ThemeManager();
    void setTheme(Theme theme);
    Theme getTheme() const;
    sf::Color getBackgroundColor() const;
    sf::Color getBarColor(int value) const;
private:
    Theme mCurrentTheme;
};

#endif // THEME_MANAGER_HPP 
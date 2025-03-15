#include "ThemeManager.hpp"
#include <cmath>

static sf::Color hsvToRgb(float hue, float saturation, float value) {
    float C = value * saturation;
    float X = C * (1 - std::fabs(std::fmod(hue / 60.0f, 2) - 1));
    float m = value - C;
    float r, g, b;
    if (hue < 60) { r = C; g = X; b = 0; }
    else if (hue < 120) { r = X; g = C; b = 0; }
    else if (hue < 180) { r = 0; g = C; b = X; }
    else if (hue < 240) { r = 0; g = X; b = C; }
    else if (hue < 300) { r = X; g = 0; b = C; }
    else { r = C; g = 0; b = X; }
    return sf::Color(static_cast<sf::Uint8>((r + m) * 255),
                     static_cast<sf::Uint8>((g + m) * 255),
                     static_cast<sf::Uint8>((b + m) * 255));
}

ThemeManager::ThemeManager() : mCurrentTheme(Theme::Dark) { }

void ThemeManager::setTheme(Theme theme) {
    mCurrentTheme = theme;
}

ThemeManager::Theme ThemeManager::getTheme() const {
    return mCurrentTheme;
}

sf::Color ThemeManager::getBackgroundColor() const {
    if (mCurrentTheme == Theme::Dark)
        return sf::Color(44, 62, 80);
    else if (mCurrentTheme == Theme::Light)
        return sf::Color(236, 240, 241);
    else
        return sf::Color::Black;
}

sf::Color ThemeManager::getBarColor(int value) const {
    float ratio = (value - 1) / 99.0f;
    float hue = 270 - ratio * 240;
    return hsvToRgb(hue, 0.8f, 0.9f);
} 
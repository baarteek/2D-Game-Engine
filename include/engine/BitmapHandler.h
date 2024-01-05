#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class BitmapHandler {
public:
    static sf::Texture loadTexture(const std::string& filename);
    static bool saveTexture(const sf::Texture& texture, const std::string& filename);
    static sf::Texture copyTexture(const sf::Texture& source);
    static sf::Texture createEmptyTexture(unsigned int width, unsigned int height, const sf::Color& fillColor = sf::Color::Transparent);
};

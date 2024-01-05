#include "BitmapHandler.h"

sf::Texture BitmapHandler::loadTexture(const std::string& filename)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        throw std::runtime_error("Failed to load texture from file: " + filename);
    }
    return texture;
}

bool BitmapHandler::saveTexture(const sf::Texture& texture, const std::string& filename)
{
    sf::Image image = texture.copyToImage();
    return image.saveToFile(filename);
}

sf::Texture BitmapHandler::copyTexture(const sf::Texture& source)
{
    sf::Texture copy;
    copy.loadFromImage(source.copyToImage());
    return copy;
}

sf::Texture BitmapHandler::createEmptyTexture(unsigned int width, unsigned int height, const sf::Color& fillColor)
{
    sf::Texture texture;
    texture.create(width, height);
    sf::Image image;
    image.create(width, height, fillColor);
    texture.update(image);
    return texture;
}

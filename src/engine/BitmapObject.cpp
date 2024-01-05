#include "BitmapObject.h"

BitmapObject::BitmapObject()
{
}

void BitmapObject::addBitmap(const sf::Texture& texture)
{
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprites.push_back(sprite);
}

void BitmapObject::draw()
{

}

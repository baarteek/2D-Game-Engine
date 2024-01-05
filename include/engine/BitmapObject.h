#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "TransformableObject.h"
#include "DrawableObject.h"

class BitmapObject : public DrawableObject, public TransformableObject {
protected:
    std::vector<sf::Sprite> sprites; 

public:
    BitmapObject();
    virtual ~BitmapObject() = default;

    void addBitmap(const sf::Texture& texture); 
    virtual void draw() override; 
};

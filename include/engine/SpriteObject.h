#pragma once

#include "BitmapObject.h"
#include "AnimatedObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SpriteObject : public BitmapObject, public AnimatedObject {
protected:
    std::vector<sf::IntRect> animationFrames;
    std::size_t currentFrame;
    float frameDuration;
    float elapsedTime;

public:
    SpriteObject();
    virtual ~SpriteObject() = default;

    void addAnimationFrame(const sf::IntRect& frame);
    virtual void animate() override;
    virtual void draw() override;
};

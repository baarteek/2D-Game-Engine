#include "SpriteObject.h"


SpriteObject::SpriteObject()
{
    currentFrame = 0;
    frameDuration = 8;
    elapsedTime = 0;
}

void SpriteObject::addAnimationFrame(const sf::IntRect& frame)
{
	animationFrames.push_back(frame);
}

void SpriteObject::animate()
{
    elapsedTime += 1;

    if (elapsedTime >= frameDuration) {
        currentFrame = (currentFrame + 1) % animationFrames.size();
        sprites[0].setTextureRect(animationFrames[currentFrame]);
        elapsedTime = 0.0f;
    }
}

void SpriteObject::draw()
{
  
}

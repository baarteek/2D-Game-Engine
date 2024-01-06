#include "Coin.h"


Coin::Coin(sf::RenderWindow* widnow, sf::Vector2f position)
{
    this->widnow = widnow;
    this->position = position;
    loadFrames();
    setPos(position);
}

void Coin::update()
{
    animate();
}

void Coin::draw()
{
    if (!sprites.empty()) {
        widnow->draw(sprites[0]);
    }
}

void Coin::setPos(sf::Vector2f position)
{
    sprites[0].setPosition(position);
}

void Coin::scale(float scaleX, float scaleY)
{
    sprites[0].scale(scaleX, scaleY);
}

sf::Vector2f Coin::getPosition()
{
    return sprites[0].getPosition();
}


void Coin::loadFrames()
{
	if (texture.loadFromFile("assets/objects/coins.png")) {
		sprites.emplace_back();
		sprites[0].setTexture(texture);

		int frameWidth = 16;
		int frameHeight = 16;
		int spacing = 0;

        int startFrame = 0;  
        int totalFrames = 5; 

        for (int i = startFrame; i < startFrame + totalFrames; ++i) {
            int x = (i % totalFrames) * (frameWidth + spacing);
            int y = (i / totalFrames) * (frameHeight + spacing);

            sf::IntRect frame(x, y, frameWidth, frameHeight);
            addAnimationFrame(frame);
        }

        sprites[0].setPosition(position.x, position.y + 6);
	}
}

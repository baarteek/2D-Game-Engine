#include "HealthPotion.h"

HealthPotion::HealthPotion(sf::RenderWindow* window, sf::Vector2f position)
{
	this->window = window;
	this->position = position;
	loadFrames();
	setPos(position);
}

void HealthPotion::update()
{
	animate();
}

void HealthPotion::draw()
{
	if (!sprites.empty()) {
		window->draw(sprites[0]);
	}
}

void HealthPotion::setPos(sf::Vector2f position)
{
	this->position = position;
	sprites[0].setPosition(position);
}

void HealthPotion::scale(float scaleX, float scaleY)
{
	sprites[0].scale(scaleX, scaleY);
}

sf::Vector2f HealthPotion::getPosition()
{
	return sprites[0].getPosition();
}

void HealthPotion::loadFrames()
{
	if (texture.loadFromFile("assets/objects/health_potions.png")) {
		sprites.emplace_back();
		sprites[0].setTexture(texture);

		int frameWidth = 18;
		int frameHeight = 18;
		int spacing = 1;

		int startFrame = 0;
		int totalFrames = 3;

		for (int i = startFrame; i < startFrame + totalFrames; ++i) {
			int x = (i % totalFrames) * (frameWidth + spacing);
			int y = (i / totalFrames) * (frameHeight + spacing);

			sf::IntRect frame(x, y, frameWidth, frameHeight);
			addAnimationFrame(frame);
		}

		sprites[0].setPosition(position.x, position.y + 6);
	}
}

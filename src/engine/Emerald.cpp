#include "Emerald.h"

Emerald::Emerald(sf::RenderWindow* window, sf::Vector2f position)
{
	this->window = window;
	this->position = position;
	loadFrames();
	setPos(position);
}

void Emerald::update()
{
	animate();
}

void Emerald::draw()
{
	if (!sprites.empty()) {
		window->draw(sprites[0]);
	}
}

void Emerald::setPos(sf::Vector2f position)
{
	this->position = position;
	sprites[0].setPosition(position);
}

sf::Vector2f Emerald::getPosition()
{
	return sprites[0].getPosition();
}

void Emerald::loadFrames()
{
	if (texture.loadFromFile("assets/objects/emeralds.png")) {
		sprites.emplace_back();
		sprites[0].setTexture(texture);

		int frameWidth = 16;
		int frameHeight = 16;
		int spacing = 0;

		int startFrame = 0;
		int totalFrames = 4;

		for (int i = startFrame; i < startFrame + totalFrames; ++i) {
			int x = (i % totalFrames) * (frameWidth + spacing);
			int y = (i / totalFrames) * (frameHeight + spacing);

			sf::IntRect frame(x, y, frameWidth, frameHeight);
			addAnimationFrame(frame);
		}

		sprites[0].setPosition(position.x, position.y + 6);
	}
}

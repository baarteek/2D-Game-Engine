#include "Potion.h"

Potion::Potion(sf::RenderWindow* window, sf::Vector2f position, std::string path)
{
	this->window = window;
	this->position = position;
	loadFrames(path);
	setPos(position);
}

void Potion::update()
{
	animate();
}

void Potion::draw()
{
	if (!sprites.empty()) {
		window->draw(sprites[0]);
	}
}

void Potion::setPos(sf::Vector2f position)
{
	this->position = position;
	sprites[0].setPosition(position);
}

void Potion::scale(float scaleX, float scaleY)
{
	sprites[0].scale(scaleX, scaleY);
}

sf::Vector2f Potion::getPosition()
{
	return sprites[0].getPosition();
}

void Potion::loadFrames(std::string path)
{
	if (texture.loadFromFile(path)) {
		sprites.emplace_back();
		sprites[0].setTexture(texture);

		int frameWidth = 18;
		int frameHeight = 18;
		int spacing = 1;

		int startFrame = 0;
		int totalFrames = 6;

		for (int i = startFrame; i < startFrame + totalFrames; ++i) {
			int x = (i % totalFrames) * (frameWidth + spacing);
			int y = (i / totalFrames) * (frameHeight + spacing);

			sf::IntRect frame(x, y, frameWidth, frameHeight);
			addAnimationFrame(frame);
		}

		sprites[0].setPosition(position.x, position.y + 6);
	}
}

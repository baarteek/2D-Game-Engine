#pragma once

#include "SpriteObject.h"

class Emerald : public SpriteObject {
public:
	Emerald(sf::RenderWindow* window, sf::Vector2f position);
	void update() override;
	void draw();
	void setPos(sf::Vector2f position);
	sf::Vector2f getPosition();

private:
	sf::RenderWindow* window;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite sprite;

	void loadFrames();
};
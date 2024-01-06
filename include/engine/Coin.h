#pragma once

#include "SpriteObject.h"

class Coin : public SpriteObject {
public:
	Coin(sf::RenderWindow* widnow);
	void update() override;
	void draw();
	void setPos(sf::Vector2f position);
	void scale(float scaleX, float scaleY);

private:
	sf::RenderWindow* widnow;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite sprite;

	void loadFrames();
};
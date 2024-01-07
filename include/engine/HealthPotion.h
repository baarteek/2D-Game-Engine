#pragma once

#include "SpriteObject.h"

class HealthPotion : public SpriteObject {
public:
	HealthPotion(sf::RenderWindow* window, sf::Vector2f position);
	void update() override;
	void draw();
	void setPos(sf::Vector2f position);
	void scale(float scaleX, float scaleY);
	sf::Vector2f getPosition();

private:
	sf::RenderWindow* window;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite sprite;

	void loadFrames();
};

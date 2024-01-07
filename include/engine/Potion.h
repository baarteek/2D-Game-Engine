#pragma once

#include "SpriteObject.h"

class Potion : public SpriteObject {
public:
	Potion(sf::RenderWindow* window, sf::Vector2f position, std::string path);
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

	void loadFrames(std::string path);
};

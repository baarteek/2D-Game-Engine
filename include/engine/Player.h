#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player : public Drawable, public Transformable {
private:
	Texture playerTexture1;
	Texture playerTexture2;
	Sprite playerSprites[2];
	Sprite* playerSprite;
	int currentTextureIndex;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Player();
	void setPosition(float x, float y);
	void animateWalking();
};
#include "Player.h"

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(*playerSprite, states);
}

Player::Player()
{
	if (!playerTexture1.loadFromFile("assets/player/player1.png") || !playerTexture2.loadFromFile("assets/player/player2.png")) {
		cerr << "Error loading player texture" << endl;
	}

	currentTextureIndex = 0;
	playerSprites[0].setTexture(playerTexture1);
	playerSprites[1].setTexture(playerTexture2);
	playerSprite = &playerSprites[currentTextureIndex];
}

void Player::setPosition(float x, float y)
{
	Transformable::setPosition(x, y);
}

void Player::animateWalking()
{
	currentTextureIndex = (currentTextureIndex + 1) % 2;
	playerSprite = &playerSprites[currentTextureIndex];
}



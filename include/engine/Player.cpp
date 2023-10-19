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
	playerX = x;
	playerY = y;
}

void Player::animateWalking()
{
    if (animationClock.getElapsedTime() > frameDuration) {
        currentTextureIndex = (currentTextureIndex + 1) % 2;
        playerSprite = &playerSprites[currentTextureIndex];
        animationClock.restart();
    }
}

void Player::setTileMap(TileMap* tileMap)
{
	this->tileMap = tileMap;
}

void Player::setVelocity(Vector2f newVelocity)
{
	velocity = newVelocity;
}

void Player::update(float deltaTime)
{
    int tileSize = 18;
    int tileX = static_cast<int>((playerX + playerSprite->getTexture()->getSize().x / 2) / tileSize);
    int tileY = static_cast<int>((playerY + playerSprite->getTexture()->getSize().y) / tileSize);

    int currentTileValue = tileMap->getTileValue(tileX, tileY);

    handleInput();

    if (isJumping(currentTileValue)) {
        velocity.y = -jumpStrength;
    }

    updateVelocity(deltaTime);
    updatePosition(tileX, tileY, tileSize, currentTileValue, deltaTime);
}

void Player::handleInput()
{
    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
        velocity.x = -playerSpeed;
        animateWalking();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
        velocity.x = playerSpeed;
        animateWalking();
    }
    else {
        velocity.x = 0.0f;
    }
}

bool Player::isJumping(int currentTileValue)
{
    return (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W)) && currentTileValue == 23;
}

void Player::updateVelocity(float deltaTime)
{
    velocity.y += tileMap->getGravity() * deltaTime;
}

void Player::updatePosition(int tileX, int tileY, int tileSize, int currentTileValue, float deltaTime)
{
    Vector2f newPosition = getPosition() + velocity * deltaTime;

    if (velocity.y > 0) {
        if (currentTileValue != 23) {
            setPosition(newPosition.x, newPosition.y);
        }
        else {
            velocity.y = 0.0f;
            float newY = tileY * tileSize - playerSprite->getTexture()->getSize().y;
            setPosition(newPosition.x, newY);
        }
    }
    else {
        setPosition(newPosition.x, newPosition.y);
    }
}

void Player::setPlayerSpeed(float speed)
{
    this->playerSpeed = speed;
}

void Player::setJumpStrenght(float strenght)
{
    this->jumpStrength = strenght;
}



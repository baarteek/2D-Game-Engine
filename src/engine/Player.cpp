#include "Player.h"

void Player::draw(RenderTarget& target, RenderStates states) const
{
    FloatRect bounds = playerSprite->getLocalBounds();
    Vector2f origin(bounds.width / 2.0f, bounds.height / 2.0f);

    Vector2f originalPosition = playerSprite->getPosition();

    states.transform *= getTransform();
    states.transform.translate(origin);
    states.transform.scale(direction, 1);
    states.transform.translate(-origin);

   playerSprite->setPosition(originalPosition);

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
    handleCollisions();

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
        direction = -1;
        animateWalking();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
        velocity.x = playerSpeed;
        direction = 1;
        animateWalking();
    }
    else {
        velocity.x = 0.0f;
    }
}

bool Player::isJumping(int currentTileValue)
{
    return (isOnCollisionTile(currentTileValue) && (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W)));
}

void Player::updateVelocity(float deltaTime)
{
    velocity.y += tileMap->getGravity() * deltaTime;
}

Vector2f Player::getPosition()
{
    return Vector2f(playerX, playerY);
}


void Player::updatePosition(int tileX, int tileY, int tileSize, int currentTileValue, float deltaTime) {
    Vector2f newPosition = getPosition() + velocity * deltaTime;

    if (velocity.y > 0) {
        if (!isOnCollisionTile(currentTileValue)) {
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

bool Player::isOnCollisionTile(int currentTileValue) {
    bool isOnCollisionTile = false;
    for (int i = 0; i < tileMap->getCollisionTilesCount(); i++) {
        if (tileMap->getCollisionTileID(i) == currentTileValue)
            isOnCollisionTile = true;
    }
    return isOnCollisionTile;
}

void Player::handleCollisions()
{
    int tileSize = 18;
    int tileX = static_cast<int>((playerX + playerSprite->getTexture()->getSize().x / 2) / tileSize);
    int tileY = static_cast<int>((playerY + playerSprite->getTexture()->getSize().y) / tileSize);

    int currentTileValue = tileMap->getTileValue(tileX, tileY);

    if (velocity.x > 0) {
        int nextTileX = static_cast<int>((playerX + playerSprite->getTexture()->getSize().x / 2 + tileSize / 2) / tileSize);
        int nextTileY = static_cast<int>((playerY + playerSprite->getTexture()->getSize().y / 2) / tileSize);
        int nextTileValue = tileMap->getTileValue(nextTileX, nextTileY);

        if (isOnCollisionTile(nextTileValue)) {
            velocity.x = 0.0f;
            float newX = nextTileX * tileSize - playerSprite->getTexture()->getSize().x / 2 - (tileSize / 2);
            setPosition(newX, playerY);
        }
    }
    else if (velocity.x < 0) {
        int prevTileX = static_cast<int>((playerX + playerSprite->getTexture()->getSize().x / 2 - tileSize / 2) / tileSize);
        int prevTileY = static_cast<int>((playerY + playerSprite->getTexture()->getSize().y / 2) / tileSize);
        int prevTileValue = tileMap->getTileValue(prevTileX, prevTileY);

        if (isOnCollisionTile(prevTileValue)) {
            velocity.x = 0.0f;
            float newX = (prevTileX + 1) * tileSize + playerSprite->getTexture()->getSize().x / 2 - (tileSize);
            setPosition(newX, playerY);
        }
    }
}

void Player::setHealth(int helath)
{
    this->health = helath;
}

int Player::getHealth()
{
    return health;
}

void Player::decreaseHealth(int damage)
{
    health -= damage;
}

Sprite Player::getSprite()
{
    return playerSprites[0];
}

void Player::setPlayerSpeed(float speed)
{
    this->playerSpeed = speed;
}

void Player::setJumpStrenght(float strenght)
{
    this->jumpStrength = strenght;
}



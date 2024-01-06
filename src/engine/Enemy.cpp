#include "Enemy.h"


Enemy::Enemy(sf::RenderWindow* widnow, const sf::Vector2f& position, TileMap& tileMap, int speed, int helath) : tileMap(tileMap)
{
    this->widnow = widnow;
    this->speed = speed;
    this->health = helath;
    this->position = position;

    loadFrames();
}

void Enemy::loadFrames()
{
    if (texture.loadFromFile("assets/enemy/characters.png")) {

        sprites.emplace_back();
        sprites[0].setTexture(texture);

        int frameWidth = 24;
        int frameHeight = 24;
        int spacing = 1;

        int tilesPerRow = 9;

        for (int i = 18; i <= 20; ++i) {
            int x = (i % tilesPerRow) * (frameWidth + spacing);
            int y = (i / tilesPerRow) * (frameHeight + spacing);

            sf::IntRect frame(x, y, frameWidth, frameHeight);
            addAnimationFrame(frame);
        }

        position.y += 6;
        sprites[0].setPosition(position.x, position.y);
    }
}

bool Enemy::detectCollision() {
    sf::FloatRect enemyBounds = sprites[0].getGlobalBounds();

    int tileSize = tileMap.tileSize.x;

    int leftX = static_cast<int>(enemyBounds.left / tileSize);
    int rightX = static_cast<int>((enemyBounds.left + enemyBounds.width) / tileSize);
    int topY = static_cast<int>(enemyBounds.top / tileSize);
    int bottomY = static_cast<int>((enemyBounds.top + enemyBounds.height - 2) / tileSize);

    for (int y = topY; y <= bottomY; ++y) {
        int tileValueLeft = tileMap.getTileValue(leftX, y);
        if (std::find(tileMap.collisionTiles.begin(), tileMap.collisionTiles.end(), tileValueLeft) != tileMap.collisionTiles.end()) {
            return true;
        }
        int tileValueRight = tileMap.getTileValue(rightX, y);
        if (std::find(tileMap.collisionTiles.begin(), tileMap.collisionTiles.end(), tileValueRight) != tileMap.collisionTiles.end()) {
            return true;
        }
    }

    return false;
}



bool Enemy::isEdgeOfPlatform() {
    sf::FloatRect enemyBounds = sprites[0].getGlobalBounds();

    int tileSize = tileMap.tileSize.x;

    int leftX = static_cast<int>(enemyBounds.left / tileSize);
    int rightX = static_cast<int>((enemyBounds.left + enemyBounds.width) / tileSize);
    int bottomY = static_cast<int>((enemyBounds.top + enemyBounds.height) / tileSize);

    int tileValueLeft = tileMap.getTileValue(leftX, bottomY + 1); 
    if (tileValueLeft == -1 || !isOnCollisionTile(tileValueLeft)) {
        return true; 
    }

    int tileValueRight = tileMap.getTileValue(rightX, bottomY + 1); 
    if (tileValueRight == -1 || !isOnCollisionTile(tileValueRight)) {
        return true;
    }

    return false;
}

bool Enemy::isOnCollisionTile(int currentTileValue)
{
    bool isOnCollisionTile = false;
    for (int i = 0; i < tileMap.getCollisionTilesCount(); i++) {
        if (tileMap.getCollisionTileID(i) == currentTileValue)
            isOnCollisionTile = true;
    }
    return isOnCollisionTile;
}

void Enemy::flip() {
    sprites[0].setOrigin(sprites[0].getLocalBounds().width / 2, sprites[0].getLocalBounds().height / 2);
    sf::Vector2f originalPosition = sprites[0].getPosition();
    sf::Vector2f currentScale = sprites[0].getScale();

    sprites[0].setScale(-currentScale.x, currentScale.y);  

    sprites[0].setPosition(originalPosition.x, originalPosition.y);
}


void Enemy::update()
{
    if (isEdgeOfPlatform() ||detectCollision()) {
        movingLeft = !movingLeft;
        flip();
    }

    float moveX = movingLeft ? -speed : speed;
    sprites[0].move(moveX, 0);
    animate();
}

void Enemy::draw()
{
    if (!sprites.empty()) {
        widnow->draw(sprites[0]);
    }
}

void Enemy::setSpeed(int speed)
{
    this->speed = speed;
}

void Enemy::setHealth(int health)
{
    this->health = health;
}

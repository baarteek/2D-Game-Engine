#include "Enemy.h"


Enemy::Enemy(sf::RenderWindow* widnow, const sf::Vector2f& position, int speed, int helath)
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

        position.y -= 5;
        sprites[0].setPosition(position.x, position.y);
    }
}

void Enemy::update()
{
    sprites[0].move(-speed, 0);
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

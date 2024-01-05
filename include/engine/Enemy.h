#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteObject.h"

class Enemy : public SpriteObject {
public:
    Enemy(sf::RenderWindow* widnow, const sf::Vector2f& position, int speed, int helath);
    void update() override;
    void draw();
    void setSpeed(int speed);
    void setHealth(int health);

private:
    sf::RenderWindow* widnow;
    sf::Texture texture;
    sf::Vector2f position;
    sf::Sprite sprite;
    float speed;
    int health;

    void loadFrames();
};

#endif

#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include "SpriteObject.h"
#include "TileMap.h"


class Enemy : public SpriteObject {
public:
    Enemy(sf::RenderWindow* widnow, const sf::Vector2f& position, TileMap& tileMap, int speed, int helath);
    void update() override;
    void draw();
    void setSpeed(int speed);
    void setHealth(int health);
    Sprite getSprite();
    sf::Vector2f getPosition();
   

private:
    sf::RenderWindow* widnow;
    sf::Texture texture;
    sf::Vector2f position;
    TileMap& tileMap;
    sf::Sprite sprite;
    float speed;
    int health;
    bool movingLeft = true;

    void loadFrames();
    bool detectCollision();
    bool isEdgeOfPlatform();
    bool isOnCollisionTile(int currentTileValue);
    void flip();
};

#endif

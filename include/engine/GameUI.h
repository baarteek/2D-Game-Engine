#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class GameUI {
public:
    GameUI();
    void setHealth(int health);
    void update(float deltaTime, sf::Vector2f playerPosition);
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    std::vector<sf::Texture> healthTextures;
    std::vector<sf::Sprite> healthSprites;
    sf::Vector2f uiOffset;
    int playerHealth;

    void updateHealthSprite();
};


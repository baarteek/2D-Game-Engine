#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>

class GameUI {
public:
    GameUI(int playerhealth);
    void setHealth(int health);
    void update(float deltaTime, sf::Vector2f playerPosition);
    void draw(sf::RenderWindow& window);
    void displayGameTime(sf::RenderWindow& window, sf::Clock clock);

private:
    sf::Font font;
    sf::Text timeText;
    std::vector<sf::Texture> healthTextures;
    std::vector<sf::Sprite> healthSprites;
    sf::Vector2f uiOffset;
    int playerHealth;

    void updateHealthSprite();
};


#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>

class GameOver {
private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text gameOverText;
    sf::Text scoresText;
    sf::Text timeText;
    sf::Text infoText;
    int scores;
    float time = NULL;
    sf::Clock clock;
    sf::Vector2f position;

    void updateScores();
    void displayGameTime();
    void centerText(sf::Text& text, float x, float y);

public:
    GameOver(sf::RenderWindow* window, int scores, sf::Clock clock, sf::Vector2f position);
    void update();
    void draw();
    void setScores(int scores);
    void setPosition(sf::Vector2f position);
};

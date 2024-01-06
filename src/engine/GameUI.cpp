#include "GameUI.h"


GameUI::GameUI(int playerhealth)
{
    this->playerHealth = playerhealth;
    uiOffset.x = -400;
    uiOffset.y = -300;

	if (!font.loadFromFile("assets/font/font.ttf")) {
		std::cerr << "Error loading game ui font" << std::endl;
	}

    timeText.setFont(font);
    timeText.setCharacterSize(24);
    timeText.setFillColor(sf::Color(195, 199, 197));

    sf::Texture fullHealthTexture;
    sf::Texture halfHealthTexture;
    sf::Texture lowHealthTexture;

    if (!fullHealthTexture.loadFromFile("assets/player/health_full.png") ||
        !halfHealthTexture.loadFromFile("assets/player/health_half.png") ||
        !lowHealthTexture.loadFromFile("assets/player/health_low.png")) {
        std::cerr << "Error loading health texture" << std::endl;
    }

    healthTextures.push_back(fullHealthTexture);
    healthTextures.push_back(halfHealthTexture);
    healthTextures.push_back(lowHealthTexture);

    for (int i = 0; i < 3; i++) {
        sf::Sprite sprite;
        sprite.setTexture(healthTextures[0]);
        sprite.setPosition(10 + i * 50, 10);
        sprite.scale(2.25, 2.25);
        healthSprites.push_back(sprite);
    }

    updateHealthSprite();
}

void GameUI::setHealth(int health)
{
	this->playerHealth = health;
    updateHealthSprite();
}

void GameUI::update(float deltaTime, sf::Vector2f playerPosition)
{
    sf::Vector2f uiPosition = playerPosition + uiOffset;

    for (auto& sprite : healthSprites) {
        sprite.setPosition(uiPosition.x + (sprite.getGlobalBounds().width + 10) * (&sprite - &healthSprites[0]), uiPosition.y);
    }
    timeText.setPosition(uiPosition.x - uiOffset.x * 1.6, uiPosition.y);
}

void GameUI::draw(sf::RenderWindow& window)
{
    for (auto& sprite : healthSprites) {
        window.draw(sprite); 
    }
}

void GameUI::updateHealthSprite()
{
    for (int i = 0; i < healthSprites.size(); i++) {
        int healthForThisSprite = std::max(0, playerHealth - i * 2);
        if (healthForThisSprite >= 2) {
            healthSprites[i].setTexture(healthTextures[0]);
        }
        else if (healthForThisSprite == 1) {
            healthSprites[i].setTexture(healthTextures[1]);
        }
        else {
            healthSprites[i].setTexture(healthTextures[2]);
        }
    }
}

void GameUI::displayGameTime(sf::RenderWindow& window, sf::Clock clock)
{
    float time = clock.getElapsedTime().asSeconds();
    int minutes = static_cast<int>(time / 60);
    int seconds = static_cast<int>(time) % 60;

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;

    timeText.setString("Time: " + ss.str());

    window.draw(timeText);
}


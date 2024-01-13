#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow* window, int scores, sf::Clock clock, sf::Vector2f position) : window(window), scores(scores), clock(clock)
{
    this->position = position;

    if (!font.loadFromFile("assets/font/font.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    gameOverText.setFont(font);
    gameOverText.setString(isLevelCompleted ? "Level Completed!" : "Game Over");
    gameOverText.setCharacterSize(76);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(100, 100);

    scoresText.setFont(font);
    scoresText.setCharacterSize(46);
    scoresText.setFillColor(sf::Color::White);

    timeText.setFont(font);
    timeText.setCharacterSize(36);
    timeText.setFillColor(sf::Color::White);

    infoText.setFont(font);
    infoText.setCharacterSize(24);
    infoText.setFillColor(sf::Color::White);
    infoText.setString("Press Enter to continue");
}

void GameOver::update()
{
    setLevelText();
    displayGameTime();
    updateScores();
}

void GameOver::updateScores()
{
    std::stringstream ss;
    ss << "Scores: " << scores;
    scoresText.setString(ss.str());
    centerText(scoresText, position.x, position.y);
}

void GameOver::displayGameTime()
{
    if (time == NULL) {
        time = clock.getElapsedTime().asSeconds();
    }
    int minutes = static_cast<int>(time / 60);
    int seconds = static_cast<int>(time) % 60;

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;

    timeText.setString("Time: " + ss.str());
    centerText(timeText, position.x, position.y + 50);
}

void GameOver::centerText(sf::Text& text, float x, float y)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(x, y);
}

void GameOver::setLevelText()
{
    gameOverText.setString(isLevelCompleted ? "Level Completed!" : "Game Over");
    gameOverText.setCharacterSize(isLevelCompleted ? 60 : 76);
    gameOverText.setFillColor(isLevelCompleted ? sf::Color::Green : sf::Color::Red);
    centerText(gameOverText, position.x, position.y - 150);
    centerText(infoText, position.x, position.y + 200);
}

void GameOver::draw()
{
    window->draw(gameOverText);
    window->draw(scoresText);
    window->draw(timeText);
    window->draw(infoText);
}

void GameOver::setScores(int scores)
{
    this->scores = scores;
}

void GameOver::setPosition(sf::Vector2f position)
{
    this->position = position;
}

void GameOver::setIsLevelCompleted(bool isLevelCompleted)
{
    this->isLevelCompleted = isLevelCompleted;
}

bool GameOver::getIsLevelCompleted()
{
    return isLevelCompleted;
}

void GameOver::setClock(sf::Clock clock)
{
    this->clock = clock;
}

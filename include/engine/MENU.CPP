#include "Menu.h"


Menu::Menu(int windowWidth, int windowHeight)
{
	if (!font.loadFromFile("assets/font/font.ttf")) {
		cerr << "Error loading font" << endl;
	}
	else {
		playText.setFont(font);
		settingsText.setFont(font);
		exitText.setFont(font);

		playText.setString("Play");
		settingsText.setString("Settings");
		exitText.setString("Exit");

		playText.setCharacterSize(32);
		settingsText.setCharacterSize(32);
		exitText.setCharacterSize(32);

		playText.setFillColor(Color::White);
		settingsText.setFillColor(Color::White);
		exitText.setFillColor(Color::White);

		FloatRect textRect = playText.getLocalBounds();
		playText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);

		textRect = settingsText.getLocalBounds();
		settingsText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

		textRect = exitText.getLocalBounds();
		exitText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

		float centerX = windowWidth / 2;
		float centerY = windowHeight / 2;

		playText.setPosition(centerX, centerY - 50);
		settingsText.setPosition(centerX, centerY + 50);
		exitText.setPosition(centerX, centerY + 150);
	}
}

void Menu::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(playText, states);
	target.draw(settingsText, states);
	target.draw(exitText, states);
}

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Menu : public Drawable {
private:
	unsigned int width;
	unsigned int height;
	unsigned int fontSize;
	Texture backgroundTexture;
	Sprite backgroundSprite;
	Font font;
	Text playText;
	Text loadLevelText;
	Text settingsText;
	Text exitText;
	vector<Text*> menuItems;
	int selectedItem;
	Color color;
	Color selectedItemColor;

	virtual void draw(RenderTarget& target, RenderStates states) const;
	bool loadFont();
	bool loadBackground(string path);
	void setMenuText();
	void setMenuTextSize();
	void setMenuTextFillColors();
	void setMenuTextOrigins();
	void setMenuTextPositions();
	void handleMenuSelection();

public:
	Menu(unsigned int width, unsigned int height, unsigned int fontSize, string backgroundImagePath);
	void setMenu();
	void setPosition(unsigned int width, unsigned int height);
	void handleKeyPress(Keyboard::Key key);
	void setSelectedItem(int itemID);
	void setColors(Color regularColor, Color selectedItemColor);
};

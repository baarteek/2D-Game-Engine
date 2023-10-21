#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Menu : public Drawable {
private:
	Font font;
	Text playText;
	Text settingsText;
	Text exitText;

	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	Menu(int windowWidth, int windowHeight);
};

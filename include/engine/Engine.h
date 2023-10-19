#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "TileMap.h"
#include "Player.h"

using namespace sf;
using namespace std;

class Engine {
private:
	RenderWindow window;
	TileMap* map;
	Player* player;
	Color backgroundColor;

	void handleEvent();
	void renderScene();
	void initMap(string mapPath);
public:
	Engine(unsigned int width, unsigned int height, string title, int style);
	void run();
	void setFramesPerSecond(unsigned int fps);
	void setVerticalSync(bool enable);
	void handleError(string& message);
	void setBackgroundColor(int red, int green, int blue);
};
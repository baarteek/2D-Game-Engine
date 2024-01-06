#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "TileMap.h"
#include "Player.h"
#include "Menu.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "Enemy.h"
#include "GameUI.h"

using namespace sf;
using namespace std;

class Engine {
private:
	RenderWindow window;
	Clock clock;
	Clock globalClock;
	Time deltaTime;
	TileMap* map;
	Player* player;
	vector<Enemy*> enemies;
	Color backgroundColor;
	View gameView;
	View menuView;
	Menu *menu;
	GameUI* ui;

	void handleEvent();
	void renderScene();
	void initMap(string mapPath);
	void initPlayer(TileMap* tileMap);
	void initEnemy(vector<vector<int>> levelData);
public:
	Engine(unsigned int width, unsigned int height, string title, int style);
	void run();
	void setFramesPerSecond(unsigned int fps);
	void setVerticalSync(bool enable);
	void handleError(string& message);
	void setBackgroundColor(int red, int green, int blue);
	bool checkCollision(const sf::Vector2f& position1, const sf::Vector2f& position2, float minDistance);

};
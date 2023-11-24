#include "Engine.h"

Engine::Engine(unsigned int width, unsigned int height, string title, int style)
{
	window.create(VideoMode(width, height), title, style);
	gameView.setSize(width, height);
	menuView.setSize(width, height);
	menuView.setCenter(width / 2, height / 2);
	setBackgroundColor(47, 145, 250);
	initMap("assets/maps/first_map.txt");
	initPlayer(map);
	menu = new Menu(width, height, 40, "assets/menu/backgroundMenu.png");
	menu->inMenuMode = false;
}

void Engine::initMap(string mapPath)
{
	vector<vector<int>> levelData;
	if (FileReader::readMapFile(mapPath, levelData)) {
		map = new TileMap();
		map->load("assets/tilemap.png", sf::Vector2u(18, 18), levelData);
		map->setGravity(500);
		vector<int> collisionTilesID = { 1, 2, 3, 4, 5, 6, 7, 21, 22, 23, 24, 25, 26, 41, 42, 43, 44, 61, 62, 63, 64, 81, 82, 83, 84, 101, 102, 103, 104, 121, 122, 123, 124, 141, 142, 143, 144};
		map->setCollisonTilesID(collisionTilesID);
	}
}

void Engine::initPlayer(TileMap* tileMap)
{
	player = new Player();
	player->setPosition(50, 50);
	player->setTileMap(tileMap);
	player->setVelocity(Vector2f(0, 150));
	player->setJumpStrenght(200);
	player->setPlayerSpeed(150);
}

void Engine::run()
{
	while (window.isOpen()) {
		handleEvent();
		renderScene();
	}
}

void Engine::handleEvent()
{
	Event event;
	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				menu->inMenuMode = !menu->inMenuMode;
				menu->setPosition(menuView.getSize().x, menuView.getSize().y);
				menu->setMenu();
				menu->restartMenuItems();
			}
			if (menu->inMenuMode) {
				menu->handleKeyPress(event.key.code);
			}
			break;
		}
	}
}

void Engine::renderScene()
{
	deltaTime = clock.restart();
	window.clear(backgroundColor);

	Point2D* point = new Point2D(10, 10, &window);
	point->scale(50, 10);
	point->draw();

	if (!menu->inMenuMode) {
		setBackgroundColor(47, 145, 250);
		window.draw(*map);
		window.draw(*player);
		player->update(deltaTime.asSeconds());
		gameView.setCenter(player->getPosition());
		window.setView(gameView);
	}
	else {
		window.setView(menuView);
		window.draw(*map);
		window.draw(*player);
		window.draw(*menu);
	}
	
	window.display();
}

void Engine::setFramesPerSecond(unsigned int fps)
{
	window.setFramerateLimit(fps);
}

void Engine::setVerticalSync(bool enable)
{
	window.setVerticalSyncEnabled(enable);
}

void Engine::handleError(string& message)
{
	cerr << "Error: " << message << endl;
}

void Engine::setBackgroundColor(int red, int green, int blue)
{
	backgroundColor.r = red;
	backgroundColor.g = green;
	backgroundColor.b = blue;
}



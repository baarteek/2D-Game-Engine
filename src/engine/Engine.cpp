#include "Engine.h"

Engine::Engine(unsigned int width, unsigned int height, string title, int style)
{
	window.create(VideoMode(width, height), title, style);
	setBackgroundColor(47, 145, 250);
	initMap("assets/maps/first_map.txt");
	
	player = new Player();
	player->setPosition(50, 50);
}

void Engine::initMap(string mapPath)
{
	vector<vector<int>> levelData;
	if (FileReader::readMapFile(mapPath, levelData)) {
		map = new TileMap();
		map->load("assets/tilemap.png", sf::Vector2u(18, 18), levelData);
	}
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
		}
	}
}

void Engine::renderScene()
{
	window.clear(backgroundColor);

	window.draw(*map);
	window.draw(*player);

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

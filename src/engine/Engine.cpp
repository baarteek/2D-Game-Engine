#include "Engine.h"

Engine::Engine(unsigned int width, unsigned int height, string title, int style)
{
	window.create(VideoMode(width, height), title, style);
	globalClock.restart();
	gameView.setSize(width, height);
	menuView.setSize(width, height);
	menuView.setCenter(width / 2, height / 2);
	setBackgroundColor(47, 145, 250);
	initMap("assets/maps/first_map.txt");
	initPlayer(map);
	menu = new Menu(width, height, 40, "assets/menu/backgroundMenu.png");
	menu->inMenuMode = false;
	ui = new GameUI(&window, player->getHealth(), 0);
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

		initEnemy(levelData);
		initCoins(levelData);
		initEmeralds(levelData);
		initPotions(levelData);
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
	player->setHealth(6);
	player->setClock(&globalClock);
}

void Engine::initEnemy(vector<vector<int>> levelData)
{
	srand(time(NULL));
	for (int y = 0; y < levelData.size(); y++) {
		for (int x = 0; x < levelData[y].size(); x++) {
			if (levelData[y][x] == 199) {
				sf::Vector2f enemyPosition(x * 18, y * 18);
				int enemySpeed = rand() % 3 + 1;
				std::cout << enemySpeed << std::endl;
				enemies.push_back(new Enemy(&window, enemyPosition, *map, enemySpeed, 1));
			}
		}
	}
}

void Engine::initCoins(vector<vector<int>> levelData)
{
	for (int y = 0; y < levelData.size(); y++) {
		for (int x = 0; x < levelData[y].size(); x++) {
			if (levelData[y][x] == 152) {
				sf::Vector2f coinPosition(x * 18, y * 18);
				coins.push_back(new Coin(&window, coinPosition));
			}
		}
	}
}

void Engine::initEmeralds(vector<vector<int>> levelData)
{
	for (int y = 0; y < levelData.size(); y++) {
		for (int x = 0; x < levelData[y].size(); x++) {
			if (levelData[y][x] == 153) {
				sf::Vector2f coinPosition(x * 18, y * 18);
				emeralds.push_back(new Emerald(&window, coinPosition));
			}
		}
	}
}

void Engine::initPotions(vector<vector<int>> levelData)
{
	for (int y = 0; y < levelData.size(); y++) {
		for (int x = 0; x < levelData[y].size(); x++) {
			if (levelData[y][x] == 162) {
				sf::Vector2f healthPotionsPosition(x * 18, y * 18);
				healthPotions.push_back(new Potion(&window, healthPotionsPosition, "assets/objects/health_potions.png"));
			}
			else if (levelData[y][x] == 163) {
				sf::Vector2f speedPotionsPosition(x * 18, y * 18);
				speedPotions.push_back(new Potion(&window, speedPotionsPosition, "assets/objects/speed_potions.png"));
			}
			else if (levelData[y][x] == 164) {
				sf::Vector2f jumpPotionsPosition(x * 18, y * 18);
				jumpPotions.push_back(new Potion(&window, jumpPotionsPosition, "assets/objects/jump_potions.png"));
			}
		}
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


	if (!menu->inMenuMode) {
		setBackgroundColor(47, 145, 250);
		window.draw(*map);
		ui->displayGameTime(globalClock);
		window.draw(*player);

		updateEnemy();
		updateCoins();
		updateEmeralds();
		updatePotions();

		player->update(deltaTime.asSeconds());

		ui->draw();
		ui->update(deltaTime.asSeconds(), player->getPosition());

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

void Engine::updateEnemy()
{
	for (Enemy* enemy : enemies) {
		enemy->update();
		enemy->draw();

		if (checkCollision(player->getPosition(), enemy->getSprite().getPosition(), 25)) {
			player->decreaseHealth(1, &globalClock);
			player->hit();
			ui->setHealth(player->getHealth());
		}
	}
}

void Engine::updateCoins()
{
	for (auto it = coins.begin(); it != coins.end();) {
		Coin* coin = *it;
		coin->update();
		coin->draw();

		if (checkCollision(player->getPosition(), coin->getPosition(), 20)) {
			ui->addScores(1);
			delete coin;
			it = coins.erase(it);
		}
		else {
			++it;
		}
	}
}

void Engine::updateEmeralds()
{
	for (auto it = emeralds.begin(); it != emeralds.end();) {
		Emerald* emerald = *it;
		emerald->update();
		emerald->draw();

		if (checkCollision(player->getPosition(), emerald->getPosition(), 20)) {
			ui->addScores(10);
			delete emerald;
			it = emeralds.erase(it);
		}
		else {
			++it;
		}
	}
}

void Engine::updatePotions()
{
	for (auto it = healthPotions.begin(); it != healthPotions.end();) {
		Potion* healtpotion = *it;
		healtpotion->update();
		healtpotion->draw();

		if (checkCollision(player->getPosition(), healtpotion->getPosition(), 20)) {
			if (player->getHealth() < 6) {
				player->setHealth(player->getHealth() + 1);
				ui->setHealth(player->getHealth());
			}
			delete healtpotion;
			it = healthPotions.erase(it);
		}
		else {
			++it;
		}
	}

	for (auto it = speedPotions.begin(); it != speedPotions.end();) {
		Potion* speedPotion = *it;
		speedPotion->update();
		speedPotion->draw();

		if (checkCollision(player->getPosition(), speedPotion->getPosition(), 20)) {
			player->applySpeedBoost(10, 225);
			ui->activatePotion(10);
			delete speedPotion;
			it = speedPotions.erase(it);
		}
		else {
			++it;
		}
	}

	for (auto it = jumpPotions.begin(); it != jumpPotions.end();) {
		Potion* jumpPotion = *it;
		jumpPotion->update();
		jumpPotion->draw();

		if (checkCollision(player->getPosition(), jumpPotion->getPosition(), 20)) {
			player->applyJumpBoost(10, 300);
			ui->activateJumpPotion(10);
			delete jumpPotion;
			it = jumpPotions.erase(it);
		}
		else {
			++it;
		}
	}
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

bool Engine::checkCollision(const sf::Vector2f& position1, const sf::Vector2f& position2, float minDistance) {
	float dx = position1.x - position2.x;
	float dy = position1.y - position2.y;
	float distance = std::sqrt(dx * dx + dy * dy);

	return distance < minDistance;
}




#include "Engine.h"

Engine::Engine(unsigned int width, unsigned int height, string title, int style)
{
	window.create(VideoMode(width, height), title, style);
	primitive = new PrimitiveRenderer(window);
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
	window.clear(Color::Black);

	primitive->drawCircle(50, 50, 25, Color::Green);
	primitive->drawRectangle(300, 300, 50, 80, Color::Yellow);
	std::vector<sf::Vector2f> points = {
	   sf::Vector2f(100, 100),
	   sf::Vector2f(200, 100),
	   sf::Vector2f(150, 200)
	};
	primitive->drawPolygon(points, Color::Magenta);

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

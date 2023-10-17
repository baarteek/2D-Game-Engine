#include "Engine.h"

Engine::Engine(unsigned int width, unsigned int height, string title, int style)
{
	window.create(VideoMode(width, height), title, style);
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

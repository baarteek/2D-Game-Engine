#include <Engine.h>
#include <SFML/Graphics.hpp>


int main() {
	Engine engine(800, 600, "2DGameEngine", sf::Style::Close | sf::Style::Resize);
	engine.setFramesPerSecond(60);
	engine.setVerticalSync(true);

	try {
		engine.run();
	} catch (const std::exception& e) {
		string error_message = e.what();
		engine.handleError(error_message);
	}

	return 0;
}
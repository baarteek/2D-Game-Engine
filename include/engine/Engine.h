#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "PrimitiveRenderer.h"

using namespace sf;
using namespace std;

class Engine {
private:
	RenderWindow window;
	PrimitiveRenderer* primitive;

	void handleEvent();
	void renderScene();
public:
	Engine(unsigned int width, unsigned int height, string title, int style);
	void run();
	void setFramesPerSecond(unsigned int fps);
	void setVerticalSync(bool enable);
	void handleError(string& message);
};
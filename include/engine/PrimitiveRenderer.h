#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class PrimitiveRenderer {
private:
	RenderWindow& window;

public:
	PrimitiveRenderer(RenderWindow& renderWindow);
	void drawCircle(float x, float y, float radius, Color color);
	void drawRectangle(float x, float y, float width, float height, Color color);
	void drawPolygon(std::vector<Vector2f>& points, Color color);
};
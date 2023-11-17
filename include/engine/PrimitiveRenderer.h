#pragma once

#include <SFML/Graphics.hpp>
#include "math.h"

using namespace sf;
using namespace std;

class PrimitiveRenderer {
private:
	const float PI = 3.14159265358979323846f;
	RenderWindow& window;

public:
	PrimitiveRenderer(RenderWindow& renderWindow);
	void drawPixel(float x, float y, Vertex& point);
	void drawCircle(float x, float y, float radius, Color color);
	void drawCircleWithSymmetryAlgorithm(float x, float y, float radius, Color color);
	void drawEllipse(float x, float y, float radiusX, float radiusY, Color color);
	void drawRectangle(float x, float y, float width, float height, Color color);
	void drawPolygon(std::vector<Vector2f>& points, Color color);
	void drawLine(int x0, int y0, int x1, int y1, Color lineColor);
};
#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include "math.h"
#include "Point2D.h"


using namespace sf;
using namespace std;


class PrimitiveRenderer {
private:
	const float PI = 3.14159265358979323846f;
	RenderWindow* window;

	bool checkForIntersectingLines(const std::vector<Point2D>& points);
	bool doLinesIntersect(const Point2D& p1, const Point2D& q1, const Point2D& p2, const Point2D& q2);
	bool onSegment(Point2D p, Point2D q, Point2D r);


public:
	PrimitiveRenderer(RenderWindow* renderWindow);
	Color getPixelColor(int x, int y);
	void drawPixel(float x, float y, Vertex& point);
	void drawCircle(float x, float y, float radius, Color color);
	void drawCircleWithSymmetryAlgorithm(float x, float y, float radius, Color color);
	void drawEllipse(float x, float y, float radiusX, float radiusY, Color color);
	void drawRectangle(float x, float y, float width, float height, Color color);
	void drawPolygon(std::vector<Vector2f>& points, Color color);
	void drawPoint2DPolygon(const std::vector<Point2D>& points, sf::Color color);
	void drawLine(int x0, int y0, int x1, int y1, Color lineColor);
};
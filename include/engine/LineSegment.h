#pragma once

#include "PrimitiveRenderer.h"
#include "Point2D.h"

using namespace sf;

class LineSegment {
private:
	Point2D start;
	Point2D end;

public:
	LineSegment(Point2D start, Point2D end);
	Point2D getStart();
	Point2D getEnd();
	void setStart(Point2D start);
	void setEnd(Point2D end);
	void draw(PrimitiveRenderer& renderer, Color color = Color::Black);
};
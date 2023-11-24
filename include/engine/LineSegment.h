#pragma once

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "ShapeObject.h"

using namespace sf;

class LineSegment : public ShapeObject {
private:
	PrimitiveRenderer* primitive;
	Color color;
	Point2D start;
	Point2D end;

public:
	LineSegment(Point2D start, Point2D end, PrimitiveRenderer* primitive, Color color);
	Point2D getStart();
	Point2D getEnd();
	void setStart(Point2D start);
	void setEnd(Point2D end);
	void update() override;
	void draw() override;
	void translate(float dx, float dy) override;
	void rotate(float angle) override;
	void scale(float sx, float sy) override;
};
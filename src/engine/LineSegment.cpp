#include "LineSegment.h"

LineSegment::LineSegment(Point2D start, Point2D end)
{
	this->start = start;
	this->end = end;
}

Point2D LineSegment::getStart()
{
	return start;
}

Point2D LineSegment::getEnd()
{
	return end;
}

void LineSegment::setStart(Point2D start)
{
	this->start = start;
}

void LineSegment::setEnd(Point2D end)
{
	this->end = end;
}

void LineSegment::draw(PrimitiveRenderer& renderer, Color color)
{
	int x0 = (int)start.getX();
	int y0 = (int)start.getY();
	int x1 = (int)end.getX();
	int y1 = (int)end.getY();

	renderer.drawLine(x0, y0, x1, y1, color);
}

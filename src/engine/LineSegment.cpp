#include "LineSegment.h"


LineSegment::LineSegment(Point2D start, Point2D end, PrimitiveRenderer* primitive, Color color)
{
	this->start = start;
	this->end = end;
	this->primitive = primitive;
	this->color = color;
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

void LineSegment::update()
{
}

void LineSegment::draw()
{
	int x0 = (int)start.getX();
	int y0 = (int)start.getY();
	int x1 = (int)end.getX();
	int y1 = (int)end.getY();

	primitive->drawLine(x0, y0, x1, y1, color);
}

void LineSegment::translate(float dx, float dy)
{
	start.translate(dx, dy);
	end.translate(dx, dy);
}

void LineSegment::rotate(float angle)
{
	Point2D center((start.getX() + end.getX()) / 2, (start.getY() + end.getY()) / 2, NULL);
	start.rotateAroundPoint(center, angle);
	end.rotateAroundPoint(center, angle);
}

void LineSegment::scale(float sx, float sy)
{
	Point2D center((start.getX() + end.getX()) / 2, (start.getY() + end.getY()) / 2, NULL);
	start.scaleFromPoint(center, sx, sy);
	end.scaleFromPoint(center, sx, sy);
}

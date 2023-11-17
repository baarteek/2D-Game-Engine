#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Point2D::getX()
{
	return x;
}

float Point2D::getY()
{
	return y;
}

void Point2D::setX(float newX)
{
	x = newX;
}

void Point2D::setY(float newY)
{
	y = newY;
}

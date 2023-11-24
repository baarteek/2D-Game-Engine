#include "Point2D.h"


Point2D::Point2D(float x, float y, RenderWindow* window)
{
	this->x = x;
	this->y = y;
	this->window = window;
}

void Point2D::update()
{
}

void Point2D::draw()
{
	if (window) {
		CircleShape shape(5);
		shape.setPosition(x, y);
		shape.setFillColor(Color::Red);

		window->draw(shape);
	}
}

void Point2D::translate(float dx, float dy)
{
	TransformableObject::translate(dx, dy);
}

void Point2D::rotate(float angle)
{
	TransformableObject::rotate(angle);
}

void Point2D::scale(float sx, float sy)
{
	TransformableObject::scale(sx, sy);
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

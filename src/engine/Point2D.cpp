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

void Point2D::rotateAroundPoint(Point2D pivot, float angle)
{
	float rad = angle * 3.14159653 / 180.0;

	float translatedX = x - pivot.getX();
	float translatedY = y - pivot.getY();

	float rotatedX = translatedX * cos(rad) - translatedY * sin(rad);
	float rotatedY = translatedX * sin(rad) + translatedY * cos(rad);

	x = rotatedX + pivot.getX();
	y = rotatedY + pivot.getY();
}

void Point2D::scaleFromPoint(Point2D pivot, float sx, float sy)
{
	float translatedX = x - pivot.getX();
	float translatedY = y - pivot.getY();

	translatedX *= sx;
	translatedY *= sy;

	x = translatedX + pivot.getX();
	y = translatedY + pivot.getY();
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

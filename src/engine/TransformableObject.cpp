#include "TransformableObject.h"

TransformableObject::TransformableObject() : x(0), y(0), rotation(0), scaleX(1), scaleY(1) {}

void TransformableObject::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void TransformableObject::setRotation(float angle)
{
	this->rotation = angle;
}

void TransformableObject::setScale(float sx, float sy)
{
	this->scaleX = sx;
	this->scaleY = sy;
}

void TransformableObject::translate(float dx, float dy)
{
	x += dx;
	y += dy;
}

void TransformableObject::rotate(float angle)
{
	float rad = angle * 3.14159653 / 180.0;
	float newX = cos(rad) * x - sin(rad) * y;
	float newY = sin(rad) * x + cos(rad) * y;
	x = newX;
	y = newY;
}

void TransformableObject::scale(float sx, float sy)
{
	scaleX *= sx;
	scaleY *= sy;
}


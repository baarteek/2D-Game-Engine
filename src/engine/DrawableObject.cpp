#include "DrawableObject.h"

DrawableObject::DrawableObject() : opacity(1.0f) {}

void DrawableObject::setOpacity(float opacity)
{
	this->opacity = opacity;
}

float DrawableObject::getOpacity() const
{
	return opacity;
}


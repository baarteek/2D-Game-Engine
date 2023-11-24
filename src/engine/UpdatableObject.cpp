#include "UpdatableObject.h"

UpdatableObject::UpdatableObject() : isActive(true) {}

void UpdatableObject::setActive(bool active)
{
	isActive = active;
}

bool UpdatableObject::getActive() const
{
	return isActive;
}

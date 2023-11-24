#pragma once

#include "DrawableObject.h"
#include "TransformableObject.h"

class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual ~ShapeObject() = default;
};

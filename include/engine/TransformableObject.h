#pragma once

#include "GameObject.h"
#include <cmath>

class TransformableObject : virtual public GameObject {
protected:
    float x, y;
    float rotation;
    float scaleX, scaleY; 

public:
    TransformableObject();
    virtual ~TransformableObject() = default;

    void setPosition(float x, float y);
    void setRotation(float angle);
    void setScale(float sx, float sy);

    virtual void translate(float dx, float dy);
    virtual void rotate(float angle);
    virtual void scale(float sx, float sy);
};

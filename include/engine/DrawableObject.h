#pragma once

#include "GameObject.h"

class DrawableObject : virtual public GameObject {
protected:
    float opacity;

public:
    DrawableObject();
    virtual ~DrawableObject() = default;

    void setOpacity(float opacity);
    float getOpacity() const;

    virtual void draw() = 0;
};

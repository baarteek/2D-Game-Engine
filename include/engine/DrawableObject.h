#pragma once

class DrawableObject : virtual public GameObject {
protected:
    float opacity;

public:
    DrawableObject();
    virtual ~DrawableObject() = default;

    void setOpacity(float opacity);
    float getOpacity() const;

    void draw() override = 0; 
};

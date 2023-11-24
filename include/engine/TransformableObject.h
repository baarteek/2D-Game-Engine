#pragma once


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

    void translate(float dx, float dy) override = 0;
    void rotate(float angle) override = 0;
    void scale(float sx, float sy) override = 0;
};

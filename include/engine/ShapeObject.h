#pragma once

class ShapeObject : public DrawableObject, public TransformableObject {
public:
    ShapeObject();
    virtual ~ShapeObject() = default;

    void draw() override = 0;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

};

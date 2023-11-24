#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "ShapeObject.h"

using namespace sf;

class Point2D : public ShapeObject {
private:
    RenderWindow* window;

public:
    Point2D(float x = 0, float y = 0, RenderWindow* window = NULL);

    void update() override;
    void draw() override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    float getX();
    float getY();
    void setX(float newX);
    void setY(float newY);
};

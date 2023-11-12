#pragma once

#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Point2D {
private:
    float x, y;

public:
    Point2D(float x = 0, float y = 0);
    float getX();
    float getY();
    void setX(float newX);
    void setY(float newY);
    void draw(PrimitiveRenderer& renderer, float radius = 5, Color color = Color::Red);
};

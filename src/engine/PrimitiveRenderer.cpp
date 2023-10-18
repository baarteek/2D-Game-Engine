#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer(RenderWindow& renderWindow) : window(renderWindow)
{
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius, Color color)
{
    CircleShape circle(radius);
    circle.setPosition(x, y);
    circle.setFillColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawRectangle(float x, float y, float width, float height, Color color)
{
    RectangleShape rectangle(Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

void PrimitiveRenderer::drawPolygon(std::vector<Vector2f>& points, Color color)
{
    ConvexShape polygon;
    polygon.setPointCount(points.size());
    for (int i = 0; i < points.size(); i++) {
        polygon.setPoint(i, points[i]);
    }
    polygon.setFillColor(color);
    window.draw(polygon);
}


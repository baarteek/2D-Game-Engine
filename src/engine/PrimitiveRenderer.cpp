#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer(RenderWindow& renderWindow) : window(renderWindow)
{
}

void PrimitiveRenderer::drawPixel(float x, float y, Vertex& point)
{
    point.position = sf::Vector2f(x, y);
    window.draw(&point, 1, Points);
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius, Color color)
{
    CircleShape circle(radius);
    circle.setPosition(x, y);
    circle.setFillColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawCircleWithSymmetryAlgorithm(float x, float y, float radius, Color color)
{
    Vertex point;
    point.color = color;

    for (double alpha = 0; alpha <= PI / 2; alpha += 0.01) {
        float dx = radius * cos(alpha);
        float dy = radius * sin(alpha);

        drawPixel(x + dx, y + dy, point);
        drawPixel(x + dx, y - dy, point);
        drawPixel(x - dx, y + dy, point);
        drawPixel(x - dx, y - dy, point);
    }
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

void PrimitiveRenderer::drawLine(int x0, int y0, int x1, int y1, Color lineColor)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    if (dx > dy) {
        int err = dx / 2;
        while (x0 != x1) {
            RectangleShape pixel(sf::Vector2f(1, 1));
            pixel.setPosition(x0, y0);
            pixel.setFillColor(lineColor);
            window.draw(pixel);
            x0 += sx;
            err -= dy;
            if (err < 0) {
                y0 += sy;
                err += dx;
            }
        }
    } else {
        int err = dy / 2;
        while (y0 != y1) {
            RectangleShape pixel(sf::Vector2f(1, 1));
            pixel.setPosition(x0, y0);
            pixel.setFillColor(lineColor);
            window.draw(pixel);
            y0 += sy;
            err -= dx;
            if (err < 0) {
                x0 += sx;
                err += dy;
            }
        }
    }
}

void PrimitiveRenderer::drawEllipse(float x, float y, float radiusX, float radiusY, sf::Color color)
{
    Vertex point;
    point.color = color;

    for (double alpha = 0; alpha <= 2 * PI; alpha += 0.01) {
        float dx = radiusX * cos(alpha);
        float dy = radiusY * sin(alpha);

        drawPixel(x + dx, y + dy, point);
        drawPixel(x + dx, y - dy, point);
        drawPixel(x - dx, y + dy, point);
        drawPixel(x - dx, y - dy, point);
    }
}


#include "PrimitiveRenderer.h"

bool PrimitiveRenderer::checkForIntersectingLines(const std::vector<Point2D>& points)
{
    size_t n = points.size();
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if ((j != i) && (j != (i + 1) % n) && (i != (j + 1) % n)) {
                if (doLinesIntersect(points[i], points[(i + 1) % n], points[j], points[(j + 1) % n])) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool PrimitiveRenderer::doLinesIntersect(const Point2D& p1, const Point2D& q1, const Point2D& p2, const Point2D& q2)
{
    auto orientation = []( Point2D p,  Point2D q,  Point2D r) -> int {
        float val = (q.getY() - p.getY()) * (r.getX() - q.getX()) - (q.getX() - p.getX()) * (r.getY() - q.getY());
        if (val == 0) return 0;  
        return (val > 0) ? 1 : 2;
        };

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

bool PrimitiveRenderer::onSegment(Point2D p, Point2D q, Point2D r)
{
    return q.getX() <= std::max(p.getX(), r.getX()) && q.getX() >= std::min(p.getX(), r.getX()) &&
        q.getY() <= std::max(p.getY(), r.getY()) && q.getY() >= std::min(p.getY(), r.getY());
}

PrimitiveRenderer::PrimitiveRenderer(RenderWindow* renderWindow) : window(renderWindow)
{
}

void PrimitiveRenderer::drawPixel(float x, float y, Vertex& point)
{
    point.position = sf::Vector2f(x, y);
    window->draw(&point, 1, Points);
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius, Color color)
{
    CircleShape circle(radius);
    circle.setPosition(x, y);
    circle.setFillColor(color);
    window->draw(circle);
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
    window->draw(rectangle);
}

void PrimitiveRenderer::drawPolygon(std::vector<Vector2f>& points, Color color)
{
    ConvexShape polygon;
    polygon.setPointCount(points.size());
    for (int i = 0; i < points.size(); i++) {
        polygon.setPoint(i, points[i]);
    }
    polygon.setFillColor(color);
    window->draw(polygon);
}

void PrimitiveRenderer::drawPoint2DPolygon(const std::vector<Point2D>& points, sf::Color color)
{
    if (points.size() < 3 || checkForIntersectingLines(points)) {
        return;
    }

    for (size_t i = 0; i < points.size(); i++) {
         Point2D current = points[i];
         Point2D next = points[(i + 1) % points.size()]; 

        drawLine(current.getX(), current.getY(), next.getX(), next.getY(), color);
    }
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
            window->draw(pixel);
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
            window->draw(pixel);
            y0 += sy;
            err -= dx;
            if (err < 0) {
                x0 += sx;
                err += dy;
            }
        }
    }
}

Color PrimitiveRenderer::getPixelColor(int x, int y)
{
    if (x < 0 || y < 0 || x >= window->getSize().x || y >= window->getSize().y) {
        return Color::Transparent;
    }

    Texture texture;
    texture.create(window->getSize().x, window->getSize().y);
    texture.update(*window);

    Image screenshot = texture.copyToImage();
    return screenshot.getPixel(x, y);
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


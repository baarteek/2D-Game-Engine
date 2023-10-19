#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class TileMap : public Drawable, public Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    VertexArray m_vertices;
    Texture m_tileset;

public:
    bool load(const string& tileset, Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};
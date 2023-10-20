#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "FileReader.h"

using namespace sf;
using namespace std;

class TileMap : public Drawable, public Transformable
{
private:
    VertexArray m_vertices;
    Texture m_tileset;
    vector<vector<int>> tiles;
    float gravity;
    vector<int> collisionTiles;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    bool load(const string& tileset, Vector2u tileSize, const vector<vector<int>>& tiles);
    const vector<vector<int>>& getTiles() const;
    int getTileValue(unsigned int x, unsigned int y) const;
    void setGravity(float gravity);
    float getGravity();
    vector<Vector2f> getAllTileCoordinates(int tileID);
    void setCollisonTilesID(vector<int> collisionTiles);
    int getCollisionTileID(int index);
    int getCollisionTilesCount() const;
};
#include "TileLoader.h"

vector<Sprite> TilemapLoader::loadTilemap(string tilemapPath, Vector2i tileSize, Vector2i mapSize)
{
    vector<Sprite> tiles;
    Texture tilemapTexture;

    if (!tilemapTexture.loadFromFile(tilemapPath)) {
        cerr << "Error loading texture" << endl;
        return tiles;
    }

    for (int y = 0; y < mapSize.y; ++y) {
        for (int x = 0; x < mapSize.x; ++x) {
            Sprite tile;
            tile.setTexture(tilemapTexture);
            tile.setTextureRect(IntRect(x * tileSize.x, y * tileSize.y, tileSize.x, tileSize.y));
            tile.setPosition(x * tileSize.x, y * tileSize.y);

            tiles.push_back(tile);
        }
    }

    return tiles;
}

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "TileMap.h"
#include "Enemy.h"

using namespace sf;
using namespace std;

class Player : public Drawable, public Transformable {
private:
	Texture playerTexture1;
	Texture playerTexture2;
	Sprite playerSprites[2];
	Sprite* playerSprite;
	int currentTextureIndex;
	TileMap* tileMap;
	Vector2f velocity;
	float playerX;
	float playerY;
	float playerSpeed;
	float jumpStrength;
	int health;
	Clock animationClock;
	Time frameDuration = seconds(0.1f);
	int direction = 1;
	float lastHitTime;
	bool isFlashing;            
	float flashDuration;        
	float lastFlashTime;       
	sf::Color originalColor;
	sf::Clock* clock;

	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	Player();
	void setPosition(float x, float y);
	void animateWalking();
	void setTileMap(TileMap* tileMap);
	void setVelocity(Vector2f newVelocity);
	void update(float deltaTime);
	void setPlayerSpeed(float speed);
	void setJumpStrenght(float strenght);
	void handleInput();
	bool isJumping(int currentTileValue);
	void updateVelocity(float deltaTime);
	void updatePosition(int tileX, int tileY, int tileSize, int currentTileValue, float deltaTime);
	Vector2f getPosition();
	bool isOnCollisionTile(int currentTileValue);
	void handleCollisions();
	void setHealth(int helath);
	int getHealth();
	void decreaseHealth(int amount, Clock* clock);
	Sprite& getSprite();
	bool canBeHit(Clock* clock);
	void hit();
	void setClock(Clock* clock);
};
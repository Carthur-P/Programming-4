#pragma once
#include "Sprite.h"
#include "Player.h"

ref class Enemy : public Sprite
{
private:
	Player^ player;

public:
	property Enemy^ Next;

	Enemy(Graphics^ canvas, Random^ rand, array<String^>^ movingFilePath, TileMap^ map, int formWidth, int formHeight, int mapWidth, int mapHeight, Player^ player);

	void drawInViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight);
	virtual void setCollisionFrame() override;
	void setDirection();
	void checkCollisionWithPlayer();
};


#pragma once
#include "Enemy.h"

ref class EnemyList
{
private:
	Enemy^ head;
	Enemy^ tail;

public:
	EnemyList();

	void addEnemy(Enemy^ enemy);
	void deleteEnemy(Enemy^ enemyToDelete);
	void drawToViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight);
	void move(TileMap^ map);
	void checkCollisonWithPlayer();
};


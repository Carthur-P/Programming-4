#pragma once
#include "TileMap.h"
#define VELOCITY 5

ref class Viewport
{
private:
	TileMap ^ map;
	Graphics^ canvas;
	int viewportWidth;
	int viewportHeight;

public:
	property int viewportWorldX;
	property int viewportWorldY;

	Viewport(Graphics^ canvas, TileMap^ startMap, int startX, int startY, int viewportWidth, int viewportHeight);

	void move(int moveX, int moveY);
	void draw();
	bool checkLeftBoundrie();
	bool checkRightBoundrie();
	bool checkTopBoundrie();
	bool checkBottomBoundrie();
};


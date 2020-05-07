#include "Viewport.h"

Viewport::Viewport(Graphics^ startCanvas, TileMap^ startMap, int startX, int startY, int width, int height)//constructor
{
	canvas = startCanvas;
	map = startMap;
	map->loadMap("../map.csv");
	viewportWorldX = startX;
	viewportWorldY = startY;
	viewportWidth = width;
	viewportHeight = height;
}

void Viewport::move(int playerX, int playerY)//moving the viewport base on its world's cordination of the whole map
{
	viewportWorldX = playerX - ((viewportWidth * 32) / 2);
	viewportWorldY = playerY - ((viewportHeight * 32) / 2);
}

void Viewport::draw()//drawing the selected portion of the map onto the form
{
	int row = viewportWorldY / 32;
	int offsetX = viewportWorldX % 32;
	int offsetY = viewportWorldY % 32;

	for (int i = 0; i < viewportHeight; i++)
	{
		int column = viewportWorldX / 32;
		for (int j = 0; j < viewportWidth; j++)
		{
			canvas->DrawImage(map->tileList->getTile(map->getMap(row, column)), j * map->tileList->getTile(map->getMap(row, column))->Width - offsetX, i * map->tileList->getTile(map->getMap(row, column))->Height - offsetY);
			column++;
		}
		row++;
	}
}

bool Viewport::checkLeftBoundrie()
{
	bool meetBoundrie = false;
	if (viewportWorldX / 32 == 0)
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}

bool Viewport::checkRightBoundrie()
{
	bool meetBoundrie;
	if ((viewportWorldX + (viewportWidth * 32)) >= (map->numColumn * 32))
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}

bool Viewport::checkTopBoundrie()
{
	bool meetBoundrie;
	if (viewportWorldY <= 0)
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}

bool Viewport::checkBottomBoundrie()
{
	bool meetBoundrie = false;
	if ((viewportWorldY + (viewportHeight * 32)) >= (map->numRow * 32))
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}
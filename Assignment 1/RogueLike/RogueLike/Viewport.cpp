#include "Viewport.h"

Viewport::Viewport(Graphics^ startCanvas, TileMap^ startMap, Point^ playerPosition, int width, int height)//constructor
{
	canvas = startCanvas;
	map = startMap;
	viewportWidth = width;
	viewportHeight = height;
	viewportWorld = gcnew Point(playerPosition->X - ((viewportWidth * 32) / 2), playerPosition->Y - ((viewportHeight * 32) / 2));
}

void Viewport::move(int moveX, int moveY)//moving the viewport base on its world's cordination of the whole map
{
	viewportWorld->X += VELOCITY * moveX;
	viewportWorld->Y += VELOCITY * moveY;
}

void Viewport::draw()//drawing the selected portion of the map onto the form
{
	int row = viewportWorld->Y / 32;
	int offsetX = viewportWorld->X % 32;
	int offsetY = viewportWorld->Y % 32;

	for (int i = 0; i < viewportHeight; i++)
	{
		int column = viewportWorld->X / 32;
		for (int j = 0; j < viewportWidth; j++)
		{
			canvas->DrawImage(map->tileList->getTile(map->getMap(row, column)), j * map->tileList->getTile(map->getMap(row, column))->Width - offsetX, i * map->tileList->getTile(map->getMap(row, column))->Height - offsetY);
			column++;
		}
		row++;
	}
}

bool Viewport::checkLeftBoundrie()//checking the left boundrie of the viewport
{
	bool meetBoundrie = false;
	if (viewportWorld->X <= 0)
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}

bool Viewport::checkRightBoundrie()//checking the right boundrie of the viewport
{
	bool meetBoundrie = false;
	if ((viewportWorld->X + (viewportWidth * 32)) >= (map->numColumn * 32))
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}

bool Viewport::checkTopBoundrie()//checking the top boundrie of the viewport
{
	bool meetBoundrie = false;
	if (viewportWorld->Y <= 0)
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}

bool Viewport::checkBottomBoundrie()//checking the bottom boundrie of the viewport
{
	bool meetBoundrie = false;
	if ((viewportWorld->Y + (viewportHeight * 32)) >= (map->numRow * 32))
	{
		meetBoundrie = true;
	}
	return meetBoundrie;
}
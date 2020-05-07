#include "Items.h"

Items::Items(Graphics^ sCanvas, Random^ random, String^ imageFilePath, TileMap^ map, Player^ p, int mapWidth, int mapHeight)//constructor
{
	canvas = sCanvas;
	rand = random;
	itemImage = gcnew Bitmap(Image::FromFile(imageFilePath));
	itemImage->MakeTransparent(itemImage->GetPixel(0, 0));
	position = gcnew Point(0, 0);
	player = p;

	//looping until can spanw is true
	bool canSpawn = false;
	do
	{
		//creating a new spawn point
		int spawnPointX = rand->Next(100, mapWidth) - 50;
		int spawnPointY = rand->Next(100, mapHeight) - 50;
		int tileX = (spawnPointX) / 32;
		int tileY = (spawnPointY) / 32;
		int tile = map->getMap(tileY, tileX);
		bool getWalk = map->tileList->getWalkable(tile);

		//if the spawn point is on a walkable tile then make then set the item position and change canSpawn to true to get out of the loop
		if (getWalk)
		{
			worldPosition = gcnew Point(spawnPointX, spawnPointY);
			canSpawn = true;
		}

	} while (canSpawn == false);

	left = worldPosition->X;
	right = (worldPosition->X + itemImage->Width);
	top = worldPosition->Y;
	bottom = (worldPosition->Y + itemImage->Height);
}

void Items::drawInViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight)//drawing item that is in the viewport to the form
{
	if ((worldPosition->X - viewportPosition->X) <= viewportWidth && (worldPosition->Y - viewportPosition->Y) <= viewportHeight)
	{
		position->X = worldPosition->X - viewportPosition->X;
		position->Y = worldPosition->Y - viewportPosition->Y;
		canvas->DrawImage(itemImage, position->X, position->Y);
	}
}

bool Items::checkCollisionWithPlayer()//checking collision with the player character
{
	bool haveCollided = true;
	if (player->bottom < top)
	{
		haveCollided = false;
	}

	if (player->top > bottom)
	{
		haveCollided = false;
	}

	if (player->left > right)
	{
		haveCollided = false;
	}

	if (player->right < left)
	{
		haveCollided = false;
	}
	return haveCollided;
}
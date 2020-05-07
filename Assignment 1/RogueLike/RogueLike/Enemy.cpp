#include "Enemy.h"

Enemy::Enemy(Graphics^ canvas, Random^ rand, array<String^>^ movingFilePath, TileMap^ map, int formWidth, int formHeight, int mapWidth, int mapHeight, Player^ p) 
	: Sprite(canvas, rand, movingFilePath, formWidth, formHeight)//constructor that will also pass variable to the parent class of Sprite 
{
	numFrame = 3;
	frameWidth = currentImage->Width / numFrame;
	frameHeight = currentImage->Height;
	position = gcnew Point(0, 0);
	player = p;

	bool canSpawn = false;
	//looping until can spanw is true
	do
	{
		//creating a new spawn point
		int spawnPointX = rand->Next(100, mapWidth) - 50;
		int spawnPointY = rand->Next(100, mapHeight) - 50;
		int tileX = (spawnPointX) / 32;
		int tileY = (spawnPointY) / 32;
		int tile = map->getMap(tileY, tileX);
		bool getWalk = map->tileList->getWalkable(tile);

		//if the spawn point is on a walkable tile then make then set the enemy position and change canSpawn to true to get out of the loop
		if (getWalk)
		{
			worldPosition = gcnew Point(spawnPointX, spawnPointY);
			canSpawn = true;
		}

	} while (canSpawn == false);
}

void Enemy::drawInViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight)//drawing enemy that is in the viewport to the form
{
	//algorithm to check if the enemy is in the viewort
	if ((worldPosition->X - viewportPosition->X) <= viewportWidth && (worldPosition->Y - viewportPosition->Y) <= viewportHeight)
	{
		position->X = worldPosition->X - viewportPosition->X;
		position->Y = worldPosition->Y - viewportPosition->Y;
		draw();
	}
}

void Enemy::setCollisionFrame()//setting the collision frame by adding or minusing to the image borders. This wil get rid of the empty space between the image border and the character itself making the collsion appear more accurate
{
	left = worldPosition->X + 20;
	right = (worldPosition->X + frameWidth) - 20;
	top = worldPosition->Y + 20;
	bottom = (worldPosition->Y + frameHeight) - 5;
}

void Enemy::setDirection()//setting the random direction that the enermy character will move in
{
	int directionController = rand->Next(4);
	if (rand->Next(6) == 5)//this will add a chance of the enemy character wandering in the same direction for more than one move 
	{
		switch (directionController)
		{
		case 0:
			imageDirection = direction::NORTH;
			break;

		case 1:
			imageDirection = direction::EAST;
			break;

		case 2:
			imageDirection = direction::SOUTH;
			break;

		case 3:
			imageDirection = direction::WEST;
			break;

		default:
			break;
		}
	}
}

void Enemy::checkCollisionWithPlayer()//checking collision with the player character with the enemy character
{
	setCollisionFrame();
	if (player->right >= left && player->left <= right && player->top <= bottom && player->bottom >= top)
	{
		//minusing 10 of the player's health if enemy collides with player 
		player->health -= 10;
	}
}
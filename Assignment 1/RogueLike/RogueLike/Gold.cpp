#include "Gold.h"

Gold::Gold(Graphics^ canvas, Random^ rand, String^ imageFilePath, TileMap^ map, Player^ player, int mapWidth, int mapHeight)
	: Items(canvas, rand, imageFilePath, map, player, mapWidth, mapHeight)//constructor that will pass variables to the parent class of Items
{
	//initialising the variable
	type = "Gold";
	value = 100;
}

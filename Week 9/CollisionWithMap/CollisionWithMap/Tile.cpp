#include "Tile.h"

Tile::Tile(String^ filePath, bool walkable)//constructor
{
	tile = gcnew Bitmap(Image::FromFile(filePath));
	isWalkable = walkable;
}


#include "Tile.h"

Tile::Tile(String^ f, bool walkable)//constructor
{
	tile = gcnew Bitmap(Image::FromFile(f));
	isWalkable = walkable;
	filePath = f;
}

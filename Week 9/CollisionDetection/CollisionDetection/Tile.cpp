#include "Tile.h"

Tile::Tile(String^ filePath)//constructor
{
	tile = gcnew Bitmap(Image::FromFile(filePath));
}

#include "TileMap.h"

TileMap::TileMap(int row, int column)//constructor
{
	numRow = row;
	numColumn = column;
	map = gcnew array<int, 2>(row, column);

	tileList = gcnew TileList(gcnew array<Tile^>(3) {
		gcnew Tile("../imageResources/Cobblestones Tile.bmp"),
		gcnew Tile("../imageResources/Dry Grass Tile.bmp"),
		gcnew Tile("../imageResources/Flower Tile.bmp")
	});
}

void TileMap::loadMap(String^ filePath)//reading a csv file which will contain numbers representing terrain type into the two demensional array
{
	StreamReader^ sr = File::OpenText(filePath);
	String^ currentLine = "";
	array<String^>^ currentLineArray;
	int rowCount = 0;

	while ((currentLine = sr->ReadLine()) != nullptr)
	{
		currentLineArray = currentLine->Split(',');
		for (int i = 0; i < numColumn; i++)
		{
			map[rowCount, i] = System::Int32::Parse(currentLineArray[i]);
		}
		rowCount++;
	}
}
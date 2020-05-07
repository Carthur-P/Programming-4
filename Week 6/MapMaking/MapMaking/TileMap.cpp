#include "TileMap.h"

TileMap::TileMap(Graphics^ startCanvas, int row, int column)//constructor
{
	canvas = startCanvas;
	numRow = row;
	numColumn = column;
	map = gcnew array<int, 2>(row, column);

	tileList = gcnew TileList(gcnew array<Tile^>(3) {
		gcnew Tile("../imageResources/Cobblestones Tile.bmp"),
		gcnew Tile("../imageResources/Dry Grass Tile.bmp"),
		gcnew Tile("../imageResources/Flower Tile.bmp")
	});
}

void TileMap::draw()//drawing all the terrain tile base on the two demensional array
{
	for (int i = 0; i < numRow; i++)
	{
		for (int j = 0; j < numColumn; j++)
		{
			canvas->DrawImage(tileList->getTile(map[i, j]), j * tileList->getTile(map[i, j])->Width, i * tileList->getTile(map[i, j])->Height);
		}
	}
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
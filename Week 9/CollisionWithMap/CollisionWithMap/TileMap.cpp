#include "TileMap.h"

TileMap::TileMap(Graphics^ sCanvas, int row, int column)//constructor
{
	canvas = sCanvas;
	numRow = row;
	numColumn = column;
	map = gcnew array<int, 2>(row, column);

	tileList = gcnew TileList(gcnew array<Tile^>(3) {
		gcnew Tile("../imageResources/Cobblestones Tile.bmp", true),
		gcnew Tile("../imageResources/Dry Grass Tile.bmp", true),
		gcnew Tile("../imageResources/Flower Tile.bmp", false)
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

void TileMap::draw()//drawing the map onto the form
{
	for (int i = 0; i < numRow; i++)
	{
		for (int j = 0; j < numColumn; j++)
		{
			canvas->DrawImage(tileList->getTile(map[i, j]), j * tileList->getTile(map[i, j])->Width, i * tileList->getTile(map[i, j])->Height);
		}
	}
}
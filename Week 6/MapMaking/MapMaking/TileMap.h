#pragma once
#include "TileList.h"
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class TileMap
{
private:
	Graphics ^ canvas;
	TileList^ tileList;
	array<int, 2>^ map;
	int numRow;
	int numColumn;

public:
	TileMap(Graphics^ canvas, int numRow, int numColumn);

	void draw();
	void loadMap(String^ filePath);

	int getMap(int row, int column) { return map[row, column]; }
	void setMap(int row, int column, int tileType) { map[row, column] = tileType; }
};


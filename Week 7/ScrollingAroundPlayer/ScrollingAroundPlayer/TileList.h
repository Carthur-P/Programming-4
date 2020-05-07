#pragma once
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileList
{
private:
	array<Tile^>^ tileArray;

public:
	TileList(array<Tile^>^ tileArray);

	Bitmap^ getTile(int index) { return tileArray[index]->getTile(); }
	void setTile(int index, Bitmap^ tileMap) { tileArray[index]->setTile(tileMap); }
};


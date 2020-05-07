#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Tile
{
private:
	Bitmap^ tile;
	bool isWalkable;
	String^ filePath;

public:
	Tile(String^ filePath, bool isWalkable);

	Bitmap^ getTile() { return tile; }
	void setTile(Bitmap^ tileMap) { tile = tileMap; }
	bool getWalkable() { 
		String^ f = filePath;
		return isWalkable; 
	}
};


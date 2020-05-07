#pragma once
#include "TileMap.h"
#include "Player.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Items
{
private:
	Graphics^ canvas;
	Random^ rand;
	Bitmap^ itemImage;

public:
	Items^ Next;
	property Point^ worldPosition;
	property Point^ position;
	property int left;
	property int right;
	property int top;
	property int bottom;
	property String^ type;
	property int value;
	property Player^ player;

	Items(Graphics^ canvas, Random^ rand, String^ imageFilePath, TileMap^ map, Player^ player, int mapWidth, int mapHeight);

	void drawInViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight);
	bool checkCollisionWithPlayer();
};


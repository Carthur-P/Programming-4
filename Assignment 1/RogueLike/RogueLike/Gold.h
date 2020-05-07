#pragma once
#include "Items.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Gold : public Items
{
public:
	Gold(Graphics^ canvas, Random^ rand, String^ imageFilePath, TileMap^ map, Player^ player, int mapWidth, int mapHeight);
};


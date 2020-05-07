#pragma once
#include "Sprite.h"
#include "Knight.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Wizard : public Sprite
{
private:
	Knight ^ knight;

public:
	Wizard ^ Next;
	property bool isChicken;

	Wizard(Graphics^ canvas, Random^ rand, String^ imageFilePath, int worldWidth, int worldHeight, Knight^ knight);

	void checkCollisionWithKnight();
};


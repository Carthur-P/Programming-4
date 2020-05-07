#pragma once
#include "Sprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Knight : public Sprite
{
public:
	Knight(Graphics^ canvas, array<String^>^ imageFilePath, int width, int height);

	void checkBoundries();
	void moveOffCenter();

	direction getImageDirection() { return imageDirection; }
	void setImageDirection(direction direction) { imageDirection = direction; }
};


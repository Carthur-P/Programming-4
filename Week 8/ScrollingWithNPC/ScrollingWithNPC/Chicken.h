#pragma once
#include "Sprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Chicken : public Sprite//inheritence
{
public:
	Chicken ^ Next;

	Chicken(Graphics^ canvas, Random^ rand, array<String^>^ imageFilePath, int formWidth, int formHeight, int worldWidth, int worldHeight);

	void setDirection();
	void drawInViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight);
	void checkWorldBoundries();
};


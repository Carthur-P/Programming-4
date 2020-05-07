#pragma once
#include "Sprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Blobbo : public Sprite
{
private:
	int direction;

public:
	Blobbo(Graphics^ canvas, Random^ rand, Bitmap^ image, int numFrame, int formWidth, int formHeight);

	virtual void move() override;
	void jump();
};


#pragma once
#define VELOCITY 5;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Sprite
{
protected:
	Graphics^ canvas;
	Random^ rand;
	Bitmap^ image;
	Point^ position;
	Point^ framePosition;
	Rectangle^ frame;
	int numFrame;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int formWidth;
	int formHeight;

public:
	Sprite^ Next; 

	Sprite(Graphics^ canvas, Random^ rand, Bitmap^ image, int numFrame, int formWidth, int formHeight);

	void draw();
	void updateFrame();
};


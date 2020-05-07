#pragma once
#define VELOCITY 10;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Sprite
{
private:
	Graphics ^ canvas;
	Random^ rand;
	Bitmap^ blobboSprite;
	Point^ position;
	Point^ framePosition;
	Rectangle^ frame;
	int numFrame;
	int currentFrame;
	int frameWidth;
	int frameHeight;

public:
	Sprite ^ Next;

	Sprite(Graphics^ canvas, Random^ rand, Bitmap^ blobboSprite, int numFrame, int formWidth, int formHeight);
	Sprite(Graphics^ canvas, Random^ rand, Bitmap^ blobboSprite, int numFrame, Point^ position);
	void draw();
	void move();
	void updateFrame();
};


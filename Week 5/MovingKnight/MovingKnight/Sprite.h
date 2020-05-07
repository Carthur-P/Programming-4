#pragma once
#define VELOCITY 5

public enum direction { NORTH, EAST, SOUTH, WEST };
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
	array<Bitmap^>^ spriteImages;
	array<Point^>^ velocityDirection;
	Rectangle^ frame;
	Point^ position;
	Bitmap^ currentImage;
	direction imageDirection;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int numFrame;

public:
	Sprite();

	void draw();
	void move();
	void updateFrame();
	void checkBoundries(int width, int height);
};


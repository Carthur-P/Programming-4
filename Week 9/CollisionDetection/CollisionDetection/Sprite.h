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
	Graphics ^ canvas;
	Random^ rand;
	array<Bitmap^>^ spriteImages;
	array<Point^>^ velocityDirection;
	Rectangle^ frame;
	Bitmap^ currentImage;
	direction imageDirection;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int numFrame;
	int formWidth;
	int formHeight;

public:
	property Point^ worldPosition;
	property Point^ position;
	property int left;
	property int right;
	property int top;
	property int bottom;

	Sprite();

	void draw();
	void drawInViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight);
	void move();
	void updateFrame();
	void setCollisoinFrame();
};


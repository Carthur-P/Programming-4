#pragma once
#define VELOCITY 5

public enum direction { NORTH, EAST, SOUTH, WEST };
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Knight
{
protected:
	Graphics^ canvas;
	Random^ rand;
	array<Bitmap^>^ spriteImages;
	array<Point^>^ velocityDirection;
	Rectangle^ frame;
	Bitmap^ currentImage;
	direction imageDirection;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int width;
	int height;
	int numFrame;

public:
	property Point^ worldPosition;
	property Point^ position;

	Knight(Graphics^ canvas, array<String^>^ imageFilePath, int formWidth, int formHeight);

	void draw();
	void move();
	void moveOffCenter(int moveX, int moveY);
	void updateFrame();
	void checkBoundries();

	direction getImageDirection() { return imageDirection; }
	void setImageDirection(direction direction) { imageDirection = direction; }
};


#pragma once
#include "TileMap.h"
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
	array<Bitmap^>^ movingImages;
	array<String^>^ movingFilePath;
	array<Point^>^ velocityDirection;
	Bitmap^ currentImage;
	Rectangle^ frame;
	int numFrame;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int formWidth;
	int formHeight;

public:
	property Point^ worldPosition;
	property Point^ position;
	property direction imageDirection;
	property int left;
	property int right;
	property int top;
	property int bottom;

	Sprite(Graphics^ canvas, Random^ rand, array<String^>^ movingFilePath, int formWidth, int formHeight);

	void draw();
	void move();
	void updateFrame();
	virtual void setCollisionFrame();
	void checkBoundries();
	bool checkWalkable(TileMap^ tm);
};


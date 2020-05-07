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

ref class Chicken 
{
private:
	Graphics ^ canvas;
	array<Bitmap^>^ spriteImages;
	array<Point^>^ velocityDirection;
	Rectangle^ frame;
	Point^ position;
	Bitmap^ currentImage;
	TileMap^ tm;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int numFrame;
	int worldWidth;
	int worldHeight;
	int left;
	int right;
	int top;
	int bottom;

public:
	property direction imageDirection;

	Chicken(Graphics^ canvas, array<String^>^ imageFilePath, TileMap^ tilemap, int formWidth, int formHeight);

	void draw();
	void move();
	void updateFrame();
	void setCollisionFrame();
	bool checkWalkable();
	void checkBoundries();
};


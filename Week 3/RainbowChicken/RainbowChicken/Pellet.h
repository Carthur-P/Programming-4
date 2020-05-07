#pragma once
#define DIAMETER 10 //setting a constant in c++
#define SPEED 10

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Pellet
{
private:
	int positionX;
	int positionY;
	Graphics^ canvas;
	Brush^ brush;
	Color^ pelletColor;
	Random^ rand;
	bool alive;

public:
	Pellet ^ next; //need this variable to use node list

public:
	Pellet(Graphics^ canvas, Random^ rand, int positionX, int positionY);
	void Draw();
	void Move();

	bool getAlive() { return alive; };
	void setAlive(bool isAlive) { alive = isAlive; }
};


#include "Pellet.h"

Pellet::Pellet(Graphics^ sCanvas, Random^ random, int x, int y)//constructor
{
	canvas = sCanvas;
	rand = random;
	positionX = x;
	positionY = y;
	pelletColor = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
	brush = gcnew SolidBrush(*pelletColor);
	next = nullptr;
	alive = true;
}

void Pellet::Draw()//drawing a pellet onto the form
{
	canvas->FillEllipse(brush, positionX, positionY, DIAMETER, DIAMETER);
}

void Pellet::Move()//moving a pellet upward from where it is created
{
	positionY -= SPEED;
	if (positionY < 0)
	{
		alive = false;
	}
}

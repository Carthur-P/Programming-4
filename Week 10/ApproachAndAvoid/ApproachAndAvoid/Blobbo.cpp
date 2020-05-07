#include "Blobbo.h"

Blobbo::Blobbo(Graphics^ canvas, Random^ rand, Bitmap^ image, int numFrame, int formWidth, int formHeight) : Sprite(canvas, rand, image, numFrame, formWidth, formHeight)
{
}

void Blobbo::move()
{
	if (int probability = rand->Next(10) > 5)
	{
		direction = rand->Next(4);
	}

	switch (direction)
	{
	case 0:
		position->X += VELOCITY;
		break;

	case 1:
		position->Y += VELOCITY;
		break;

	case 2:
		position->X -= VELOCITY;
		break;

	case 3:
		position->Y -= VELOCITY;
		break;

	default:
		break;
	}
}

void Blobbo::jump()
{
	position = gcnew Point(rand->Next(formWidth), rand->Next(formHeight));
}

#include "Chicken.h"

Chicken::Chicken(Graphics^ sCanvas, Random^ random, array<String^>^ imageFilePath, Point startPosition)//constructor
{
	spriteImages = gcnew array<Bitmap^>(4);
	for (int i = 0; i < imageFilePath->Length; i++)
	{
		spriteImages[i] = gcnew Bitmap(imageFilePath[i]);
		spriteImages[i]->MakeTransparent(spriteImages[i]->GetPixel(0, 0));
	}

	canvas = sCanvas;
	rand = random;
	currentImage = spriteImages[imageDirection];
	frameWidth = currentImage->Width / numFrame;
	frameHeight = currentImage->Height;
	worldPosition = startPosition;
	worldPosition->X += 20;
	worldPosition->Y += 20;
	position = gcnew Point(0, 0);
}

void Chicken::setDirection()//setting the random dirction that the chicken will move in
{
	int directionController = rand->Next(4);
	if (rand->Next(6) == 5)//this will add a chance of the chicken wandering in the same direction for more than one move instead of the direction being set everytime
	{
		switch (directionController)
		{
		case 0:
			imageDirection = direction::NORTH;
			break;

		case 1:
			imageDirection = direction::EAST;
			break;

		case 2:
			imageDirection = direction::SOUTH;
			break;

		case 3:
			imageDirection = direction::WEST;
			break;

		default:
			break;
		}
	}
}



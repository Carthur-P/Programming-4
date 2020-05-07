#include "Chicken.h"

Chicken::Chicken(Graphics^ sCanvas, Random^ random, array<String^>^ imageFilePath, int width, int height)//constructor
{
	canvas = sCanvas;
	rand = random;

	spriteImages = gcnew array<Bitmap^>(4);
	for (int i = 0; i < imageFilePath->Length; i++)
	{
		spriteImages[i] = gcnew Bitmap(imageFilePath[i]);
		spriteImages[i]->MakeTransparent(spriteImages[i]->GetPixel(0, 0));
	}

	currentImage = spriteImages[imageDirection];
	frameWidth = currentImage->Width / numFrame;
	frameHeight = currentImage->Height;
	position = gcnew Point(rand->Next(width), rand->Next(height));
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


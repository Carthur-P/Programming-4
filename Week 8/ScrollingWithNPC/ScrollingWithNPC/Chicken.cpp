#include "Chicken.h"

Chicken::Chicken(Graphics^ sCanvas, Random^ random, array<String^>^ imageFilePath, int width, int height, int wWidth, int wHeight)//constructor
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
	formWidth = width;
	formHeight = height;
	worldWidth = wWidth;
	worldHeight = wHeight;
	worldPosition = gcnew Point(rand->Next(worldWidth * 32), rand->Next(worldHeight * 32));
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

void Chicken::drawInViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight)
{
	if ((worldPosition->X - viewportX) <= viewportWidth && (worldPosition->Y - viewportY) <= viewportHeight)
	{
		position->X = worldPosition->X - viewportX;
		position->Y = worldPosition->Y - viewportY;
		draw();
	}
}

void Chicken::checkWorldBoundries()//checking that the sprite object's position have not gone pass the form
{
	if (worldPosition->X + frameWidth > worldWidth)
	{
		imageDirection = direction::WEST;
	}

	if (worldPosition->X < 0)
	{
		imageDirection = direction::EAST;
	}

	if (worldPosition->Y + frameHeight > worldHeight)
	{
		imageDirection = direction::NORTH;
	}

	if (worldPosition->Y < 0)
	{
		imageDirection = direction::SOUTH;
	}
}


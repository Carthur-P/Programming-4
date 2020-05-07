#include "Wizard.h"

Wizard::Wizard(Graphics^ sCanvas, Random^ random, String^ imageFilePath, int worldWidth, int worldHeight, Knight^ k)//contructor
{
	canvas = sCanvas;
	rand = random;
	currentImage = gcnew Bitmap(Image::FromFile(imageFilePath));
	currentImage->MakeTransparent(currentImage->GetPixel(0, 0));
	frameWidth = currentImage->Width / numFrame;
	frameHeight = currentImage->Height;
	worldPosition = gcnew Point(rand->Next(worldWidth), rand->Next(worldHeight));
	position = gcnew Point(0, 0);
	knight = k;
}

void Wizard::checkCollisionWithKnight()//checking collision with the knight character
{
	isChicken = true;
	if (knight->bottom < top)
	{
		isChicken = false;
	}

	if (knight->top > bottom)
	{
		isChicken = false;
	}

	if (knight->left > right)
	{
		isChicken = false;
	}

	if (knight->right < left)
	{
		isChicken = false;
	}
}
 
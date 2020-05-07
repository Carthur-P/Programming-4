#include "Knight.h"

Knight::Knight(Graphics^ sCanvas, array<String^>^ imageFilePath, int width, int height)//constuctor
{
	canvas = sCanvas;

	spriteImages = gcnew array<Bitmap^>(4);
	for (int i = 0; i < imageFilePath->Length; i++)
	{
		spriteImages[i] = gcnew Bitmap(imageFilePath[i]);
		spriteImages[i]->MakeTransparent(spriteImages[i]->GetPixel(0, 0));
	}

	currentImage = spriteImages[imageDirection];
	frameWidth = currentImage->Width / numFrame;
	frameHeight = currentImage->Height;
	worldPosition = gcnew Point(350, 240);
	position = gcnew Point(260, 150);
	formWidth = width;
	formHeight = height;
}

void Knight::moveOffCenter(int moveX, int moveY)//moving the sprite of its center position when map boundrie is met
{
	checkBoundries();
	currentImage = spriteImages[imageDirection];
	position->X += (VELOCITY * velocityDirection[imageDirection]->X);
	position->Y += (VELOCITY * velocityDirection[imageDirection]->Y);
}

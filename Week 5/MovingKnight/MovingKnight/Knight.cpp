#include "Knight.h"

Knight::Knight(Graphics^ sCanvas, array<String^>^ imageFilePath)//constuctor
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
	position = gcnew Point(300, 200);
}

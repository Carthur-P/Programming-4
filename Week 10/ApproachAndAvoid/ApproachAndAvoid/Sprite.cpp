#include "Sprite.h"

Sprite::Sprite(Graphics^ sCanvas, Random^ random, Bitmap^ sImage, int numberFrame, int width, int height)
{
	canvas = sCanvas;
	rand = random;
	image = sImage;
	numFrame = numberFrame;
	formWidth = width;
	formHeight = height;
	position = gcnew Point(rand->Next(formWidth), rand->Next(formHeight));
	framePosition = gcnew Point(0, 0);
	currentFrame = 0;
	frameWidth = image->Width / numberFrame;
	frameHeight = image->Height;
	image->MakeTransparent(image->GetPixel(0, 0));
}

void Sprite::draw()
{
	updateFrame();
	canvas->DrawImage(image, position->X, position->Y, *frame, GraphicsUnit::Pixel);
}

void Sprite::updateFrame()//updating what portion of the sprite to display 
{
	currentFrame = (currentFrame + 1) % numFrame;
	frame = gcnew Rectangle(framePosition->X, framePosition->Y, frameWidth, frameHeight);
	framePosition->X = frameWidth * currentFrame;
}
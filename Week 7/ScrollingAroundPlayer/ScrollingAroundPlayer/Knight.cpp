#include "Knight.h"

Knight::Knight(Graphics^ sCanvas, array<String^>^ imageFilePath, int formWidth, int formHeight)//constructor
{
	spriteImages = gcnew array<Bitmap^>(4);
	for (int i = 0; i < imageFilePath->Length; i++)
	{
		spriteImages[i] = gcnew Bitmap(imageFilePath[i]);
		spriteImages[i]->MakeTransparent(spriteImages[i]->GetPixel(0, 0));
	}

	canvas = sCanvas;
	numFrame = 8;
	currentFrame = 0;
	imageDirection = direction::EAST;
	velocityDirection = gcnew array<Point^>(4) { gcnew Point(0, -1), gcnew Point(1, 0), gcnew Point(0, 1), gcnew Point(-1, 0) };
	currentImage = spriteImages[imageDirection];
	frameWidth = currentImage->Width / numFrame;
	frameHeight = currentImage->Height;
	width = formWidth;
	height = formHeight;
	worldPosition = gcnew Point(500, 500);
	position = gcnew Point(260, 150);
}

void Knight::draw()//drawing the sprite animation onto the form
{
	canvas->DrawImage(currentImage, position->X, position->Y, *frame, GraphicsUnit::Pixel);
}

void Knight::move()//moving the sprite position in the direction that was set by five pixcels
{
	currentImage = spriteImages[imageDirection];
	worldPosition->X += (VELOCITY * velocityDirection[imageDirection]->X);
	worldPosition->Y += (VELOCITY * velocityDirection[imageDirection]->Y);
}

void Knight::moveOffCenter(int moveX, int moveY)//moving the sprite of its center position when map boundrie is met
{
	checkBoundries();
	currentImage = spriteImages[imageDirection];
	position->X += VELOCITY * moveX;
	position->Y += VELOCITY * moveY;
}

void Knight::updateFrame()//updating the portion of the sprite that is going to be displayed
{
	currentFrame = (currentFrame + 1) % numFrame;
	frame = gcnew Rectangle(currentFrame*frameWidth, 0, frameWidth, frameHeight);
}

void Knight::checkBoundries()//checking that the sprite object's position have not gone pass the form
{
	if (position->X + frameWidth > width)
	{
		position->X = width - frameWidth;
	}

	if (position->X < 0)
	{
		position->X = 0;
	}

	if (position->Y + frameHeight > height)
	{
		position->Y = height - frameHeight;
	}

	if (position->Y < 0)
	{
		position->Y = 0;
	}
}
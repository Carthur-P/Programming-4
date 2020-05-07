#include "Sprite.h"

Sprite::Sprite()//constructor
{
	numFrame = 8;
	currentFrame = 0;
	imageDirection = direction::EAST;
	velocityDirection = gcnew array<Point^>(4) { gcnew Point(0, -1), gcnew Point(1, 0), gcnew Point(0, 1), gcnew Point(-1, 0) };
}

void Sprite::draw()//drawing the sprite animation onto the form
{
	canvas->DrawImage(currentImage, position->X, position->Y, *frame, GraphicsUnit::Pixel);
}

void Sprite::move()//moving the sprite position in the direction that was set by five pixcels
{
	currentImage = spriteImages[imageDirection];
	worldPosition->X += (VELOCITY * velocityDirection[imageDirection]->X);
	worldPosition->Y += (VELOCITY * velocityDirection[imageDirection]->Y);
}

void Sprite::updateFrame()//updating the portion of the sprite that is going to be displayed
{
	currentFrame = (currentFrame + 1) % numFrame;
	frame = gcnew Rectangle(currentFrame*frameWidth, 0, frameWidth, frameHeight);
}

void Sprite::checkBoundries()//checking that the sprite object's position have not gone pass the form
{
	if (position->X + frameWidth > formWidth)
	{
		position->X = formWidth - frameWidth;
	}

	if (position->X < 0)
	{
		position->X = 0;
	}

	if (position->Y + frameHeight > formHeight)
	{
		position->Y = formHeight - frameHeight;
	}

	if (position->Y < 0)
	{
		position->Y = 0;
	}
}
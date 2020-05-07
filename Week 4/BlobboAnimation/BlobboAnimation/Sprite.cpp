#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, Random^ random, Bitmap^ startImage, int numberFrame, int formWidth, int FormHeight)//random starting position contructor
{
	canvas = startCanvas;
	rand = random;
	blobboSprite = startImage;
	numFrame = numberFrame;
	currentFrame = 0; 
	frameWidth = 32;
	frameHeight = 32;
	framePosition = gcnew Point(0, 0);
	blobboSprite->MakeTransparent(blobboSprite->GetPixel(0, 0));
	position = gcnew Point(rand->Next(formWidth), rand->Next(FormHeight));
}

Sprite::Sprite(Graphics^ startCanvas, Random^ random, Bitmap^ startImage, int numberFrame, Point^ startPosition)//fixed starting position constructor
{
	canvas = startCanvas;
	rand = random;
	blobboSprite = startImage;
	numFrame = numberFrame;
	currentFrame = 0;
	frameWidth = 32;
	frameHeight = 32;
	framePosition = gcnew Point(0, 0);
	blobboSprite->MakeTransparent(blobboSprite->GetPixel(0, 0));
	position = startPosition;
}

void Sprite::draw()//drawing one rectangle frame of the sprite onto the canvas
{
	canvas->DrawImage(blobboSprite, position->X, position->Y, *frame, GraphicsUnit::Pixel); //rectangle can't be a pointer 
}

void Sprite::move()//moving the blobbo character in random directions by 10 pixcels
{
	int direction = rand->Next(4);

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

void Sprite::updateFrame()//updating what portion of the sprite to display 
{
	currentFrame = (currentFrame + 1) % numFrame;
	frame = gcnew Rectangle(framePosition->X, framePosition->Y, frameWidth, frameHeight);
	framePosition->X = frameWidth * currentFrame;
}
	
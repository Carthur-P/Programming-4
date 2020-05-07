#include "Sprite.h"

Sprite::Sprite(Graphics^ sCanvas, Random^ random, array<String^>^ mFilePath, int fWidth, int fHeight)//constructor
{
	canvas = sCanvas;
	rand = random;
	movingFilePath = mFilePath;
	formWidth = fWidth;
	formHeight = fHeight;

	//making the bitmap images with the file path that was passed in
	movingImages = gcnew array<Bitmap^>(4);
	for (int i = 0; i < movingFilePath->Length; i++)
	{
		movingImages[i] = gcnew Bitmap(movingFilePath[i]);
		movingImages[i]->MakeTransparent(movingImages[i]->GetPixel(0, 0));
	}

	velocityDirection = gcnew array<Point^>(4) { gcnew Point(0, -1), gcnew Point(1, 0), gcnew Point(0, 1), gcnew Point(-1, 0) };
	imageDirection = direction::EAST;
	currentImage = movingImages[imageDirection];
	currentFrame = 0;
}

void Sprite::draw()//drawing the sprite charater onto the form
{
	updateFrame();
	canvas->DrawImage(currentImage, position->X, position->Y, *frame, GraphicsUnit::Pixel);
}

void Sprite::move()//moving the sprite character position in the direction that was set by five pixcels
{
	setCollisionFrame();
	currentImage = movingImages[imageDirection];
	worldPosition->X += (VELOCITY * velocityDirection[imageDirection]->X);
	worldPosition->Y += (VELOCITY * velocityDirection[imageDirection]->Y);
}

void Sprite::updateFrame()//updating the portion of the sprite that is going to be displayed
{
	currentFrame = (currentFrame + 1) % numFrame;
	frame = gcnew Rectangle(currentFrame*frameWidth, 0, frameWidth, frameHeight);
}

void Sprite::setCollisionFrame()
{
}

bool Sprite::checkWalkable(TileMap^ tm)//checking to see if the tile that the character is going to walk on is walkable
{
	bool walkable;
	setCollisionFrame();
	switch (imageDirection)
	{
		case NORTH:
		{
			int tile = tm->getMap(top / 32, right / 32);
			walkable = tm->tileList->getWalkable(tile);
			break;
		}

		case EAST:
		{
			int tile = tm->getMap(bottom / 32, right / 32);
			walkable = tm->tileList->getWalkable(tile);
			break;
		}

		case SOUTH:
		{
			int tile = tm->getMap(bottom / 32, left / 32);
			walkable = tm->tileList->getWalkable(tile);
			break;
		}

		case WEST:
		{
			int tile = tm->getMap(bottom / 32, left / 32);
			walkable = tm->tileList->getWalkable(tile);
			break;
		}

		default:
		{
			walkable = true;
		}
	}
	return walkable;
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
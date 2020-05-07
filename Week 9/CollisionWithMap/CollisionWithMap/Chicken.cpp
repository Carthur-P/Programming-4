#include "Chicken.h"

Chicken::Chicken(Graphics^ sCanvas, array<String^>^ imageFilePath, TileMap^ tilemap, int width, int height)//constructor
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
	worldHeight = width;
	worldWidth = height;
	frame = gcnew Rectangle(currentFrame*frameWidth, 0, frameWidth, frameHeight);
	position = gcnew Point(25, 25);
	tm = tilemap;
}

void Chicken::draw()//drawing the chicken onto the form
{
	updateFrame();
	canvas->DrawImage(currentImage, position->X, position->Y, *frame, GraphicsUnit::Pixel);
}

void Chicken::move()//moving the chicken in the direction that was set by five pixcels
{
	checkBoundries();
	currentImage = spriteImages[imageDirection];
	position->X += (VELOCITY * velocityDirection[imageDirection]->X);
	position->Y += (VELOCITY * velocityDirection[imageDirection]->Y);
}

void Chicken::updateFrame()//updating the portion of the sprite that is going to be displayed
{
	currentFrame = (currentFrame + 1) % numFrame;
	frame = gcnew Rectangle(currentFrame*frameWidth, 0, frameWidth, frameHeight);
}

void Chicken::setCollisionFrame()//setting the new point where collision will be check on the image
{
	left = position->X + 8;
	right = (position->X + frameWidth) - 8;
	top = position->Y + 8;
	bottom = (position->Y + frameHeight) - 8;
}

bool Chicken::checkWalkable()//checking to see if the tile that the chicken is going to walk on is walkable
{
	bool walkable;
	setCollisionFrame();
	switch (imageDirection)
	{
		case NORTH:
		{
			int tile = tm->getMap(top / 32, left / 32);
			walkable = tm->tileList->getIsWalkable(tile);
			break;
		}

		case EAST:
		{
			int tile = tm->getMap(top / 32, right / 32);
			walkable = tm->tileList->getIsWalkable(tile);
			break;
		}
			
		case SOUTH:
		{
			int tile = tm->getMap(bottom / 32, left / 32);
			walkable = tm->tileList->getIsWalkable(tile);
			break;
		}

		case WEST:
		{
			int tile = tm->getMap(top / 32, left / 32);
			walkable = tm->tileList->getIsWalkable(tile);
			break;
		}
		
		default:
		{
			walkable = true;
		}
	}
	return walkable;
}

void Chicken::checkBoundries()//checking that the chicken position have not gone pass the form
{
	if (position->X + frameWidth > worldWidth)
	{
		position->X = worldWidth - frameWidth;
	}

	if (position->X < 0)
	{
		position->X = 0;
	}

	if (position->Y + frameHeight > worldHeight)
	{
		position->Y = worldHeight - frameHeight;
	}

	if (position->Y < 0)
	{
		position->Y = 0;
	}
}

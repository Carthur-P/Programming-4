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

void Sprite::drawInViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight)//drawing sprite that is in the viewport to the form
{
	if ((worldPosition->X - viewportX) <= viewportWidth && (worldPosition->Y - viewportY) <= viewportHeight)
	{
		position->X = worldPosition->X - viewportX;
		position->Y = worldPosition->Y - viewportY;
		draw();
		setCollisoinFrame();
	}
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

void Sprite::setCollisoinFrame()//setting new boundries use for collisions for the sprite  
{
	left = position->X + 30;
	right = (position->X + frameWidth) - 30;
	top = position->Y + 25;
	bottom = (position->Y + frameHeight) - 25;
}

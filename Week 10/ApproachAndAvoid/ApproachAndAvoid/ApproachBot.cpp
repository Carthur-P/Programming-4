#include "ApproachBot.h"

ApproachBot::ApproachBot(Graphics^ canvas, Random^ rand, Bitmap^ image, int numFrame, int formWidth, int formHeight) : Sprite(canvas, rand, image, numFrame, formWidth, formHeight)
{
}

void ApproachBot::approach(Point^ blobboPosition)
{
	if (blobboPosition->X > position->X)
	{
		position->X += VELOCITY;
	}

	if (blobboPosition->X < position->X)
	{
		position->X -= VELOCITY;
	}

	if (blobboPosition->Y > position->Y)
	{
		position->Y += VELOCITY;
	}

	if (blobboPosition->Y < position->Y)
	{
		position->Y -= VELOCITY;
	}
}

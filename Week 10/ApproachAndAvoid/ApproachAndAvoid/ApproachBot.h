#pragma once
#include "Sprite.h"

ref class ApproachBot : public Sprite
{
public:
	ApproachBot(Graphics^ canvas, Random^ rand, Bitmap^ image, int numFrame, int formWidth, int formHeight);

	virtual void approach(Point^ blobboPosition) override;
};


#pragma once
#include "Sprite.h"

ref class SpriteList
{
private:
	Sprite^ head;
	Sprite^ tail;

public:
	SpriteList();

	void add(Sprite^ sprite);
	void draw();
	void move(Point^ blobboPosition)
};


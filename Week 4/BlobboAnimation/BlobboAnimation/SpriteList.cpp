#include "SpriteList.h"

SpriteList::SpriteList()//constructor
{
	head = nullptr;
	tail = nullptr;
}

void SpriteList::updateAllFrame()//upadating what portion of the sprite to display for all the characters in the list
{
	Sprite^ index = head;
	while (index != nullptr)
	{
		index->updateFrame();
		index = index->Next;
	}
}

void SpriteList::addSprite(Sprite^ sprite)//adding a character to the list
{
	if (head == nullptr)
	{
		head = sprite;
		tail = sprite;
	}

	else
	{
		tail->Next = sprite;
		tail = sprite;
	}
}

void SpriteList::drawAllSprite()//drawing all the characters in the list to the screen 
{
	Sprite^ index = head;
	while (index != nullptr)
	{
		index->draw();
		index = index->Next;
	}
}

void SpriteList::moveAllSprite()//moving all the character in the list 
{
	Sprite^ index = head;
	while (index != nullptr)
	{
		index->move();
		index = index->Next;
	}
}

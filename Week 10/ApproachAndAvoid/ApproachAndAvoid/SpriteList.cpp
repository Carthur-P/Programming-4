#include "SpriteList.h"

SpriteList::SpriteList()//constructor
{
	head = nullptr;
	tail = nullptr;
}

void SpriteList::add(Sprite^ sprite)//adding a new character to the list
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

void SpriteList::draw()//drawing the character in the list to the form
{
	Sprite^ index = head;
	while (index != nullptr)
	{
		index->draw();
		index = index->Next;
	}
}

void SpriteList::move(Point^ blobboPosition)
{
	Sprite^ index = head;
	while (index != nullptr)
	{
		index->approach(blobboPosition);
		index = index->Next;
	}
}
#include "ChickenList.h"

ChickenList::ChickenList()//constructor
{
	head = nullptr;
	tail = nullptr;
}

void ChickenList::addChicken(Chicken^ chicken)//adding a chicken object to the list
{
	if (head == nullptr)
	{
		head = chicken;
		tail = chicken;
	}

	else
	{
		tail->Next = chicken;
		tail = chicken;
	}
}

void ChickenList::drawAllChicken()//drawing all the chicken in the list to the form
{
	Chicken^ index = head;
	while (index != nullptr)
	{
		index->draw();
		index = index->Next;
	}
}

void ChickenList::drawChickenToViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight)
{
	Chicken^ index = head;
	while (index != nullptr)
	{
		index->drawInViewport(viewportX, viewportY, viewportWidth, viewportHeight);
		index = index->Next;
	}
}

void ChickenList::moveAllChicken()//moving all the chicken in the list
{
	Chicken^ index = head;
	while (index != nullptr)
	{
		index->move();
		index = index->Next;
	}
}

void ChickenList::updateAllChicken()//updating the sprite frame for all the chicken in the list
{
	Chicken^ index = head;
	while (index != nullptr)
	{
		index->updateFrame();
		index = index->Next;
	}
}

void ChickenList::setAllChickenDirection()//setting the random chicken movement direction for all the chicken in the list
{
	Chicken^ index = head;
	while (index != nullptr)
	{
		index->setDirection();
		index = index->Next;
	}
}

void ChickenList::checkWorldBoundries()//checking that the chicken position have not gone pass the form for all the chicken in the list 
{
	Chicken^ index = head;
	while (index != nullptr)
	{
		index->checkWorldBoundries();
		index = index->Next;
	}
}

#include "WizardList.h"

WizardList::WizardList()//constructor
{
	head = nullptr;
	tail = nullptr;
}

void WizardList::addWizard(Wizard^ wizard)//adding a new wizard character to the list
{
	if (head == nullptr)
	{
		head = wizard;
		tail = wizard;
	}

	else
	{
		tail->Next = wizard;
		tail = wizard;
	}
}

void WizardList::drawWizardToViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight)//drawing the wizard that is in the viewport to the form
{
	Wizard^ index = head;
	while (index != nullptr)
	{
		index->drawInViewport(viewportX, viewportY, viewportWidth, viewportHeight);
		index = index->Next;
	}
}

void WizardList::updateAllWizard()//updating the sprite frame for all the wizard in the list
{
	Wizard^ index = head;
	while (index != nullptr)
	{
		index->updateFrame();
		index = index->Next;
	}
}

Wizard^ WizardList::checkCollision()//checking the collision with the knight character and delete itself if true
{
	Wizard^ changingWizard = nullptr;
	Wizard^ index = head;
	while (index != nullptr)
	{
		index->checkCollisionWithKnight();
		if (index->isChicken == true)
		{
			changingWizard = index;
			deleteWizard(index);
		}
		index = index->Next;
	}
	return changingWizard;
}

void WizardList::deleteWizard(Wizard^ wizardToDelete)//deleting the wizard character from the list
{
	if (wizardToDelete == head)
	{
		Wizard^ index = head;
		if(index->Next == nullptr)
		{
			head = nullptr;
			tail = nullptr;
		}

		else
		{
			head = head->Next;
		}
	}

	else
	{
		Wizard^ index = head;
		while (index->Next != wizardToDelete)
		{
			index = index->Next;
		}
		index->Next = wizardToDelete->Next;
	}
}


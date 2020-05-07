#include "PelletList.h"

PelletList::PelletList()//constructor
{
	head = nullptr;
	tail = nullptr;
}

int PelletList::countPellet()//counting how many pellet is in the list and return the count
{
	int count = 0;
	Pellet^ index = head;

	while (index != nullptr)
	{
		count++;
		index = index->next;
	}
	return count;
}

void PelletList::moveAllPellet()//moving all the pellet in the list  
{
	Pellet^ index = head;
	while (index != nullptr)
	{
		index->Move();
		index = index->next;
	}
}

void PelletList::deleteAllPellet()//checking to see if the pellet is 'alive' and deleting the one that is not alive
{
	Pellet^ index = head;
	Pellet^ deletePellet;
	while (index != nullptr)
	{
		if (index->getAlive() == false)
		{
			deleteDeadPellet(index);
		}
		index = index->next;
	}
}

void PelletList::addPellet(Pellet^ pellet)//adding a pellet to the list
{
	if (tail == nullptr)
	{
		head = pellet;
		tail = pellet;
	}

	else
	{
		tail->next = pellet;
		tail = pellet;
	}
}

void PelletList::deleteDeadPellet(Pellet^ pelletToDelete)//pellet that have been identify as not 'alive' will be deleted from the list
{
	Pellet^ index = head;

	if (pelletToDelete == head)//if the pellet to be deleted is the head of the list
	{
		if (index->next == nullptr)//head pellet is the only pellet in the list
		{
			head = nullptr;
			tail = nullptr;
		}

		else//if there is another pellet after the head then move the head to be the next pellet
		{
			head = head->next;
		}
	}

	else//pellet to be deleted is not the head of the list
	{
		while (index != pelletToDelete)
		{
			index = index->next;
		}
		index->next = pelletToDelete->next;
	}
}

void PelletList::drawAllPellet()//drawing all the pellet in the list to the form
{
	Pellet^ index = head;
	while (index != nullptr)
	{
		index->Draw();
		index = index->next;
	}
}
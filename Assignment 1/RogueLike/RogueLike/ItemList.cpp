#include "ItemList.h"

ItemList::ItemList()//constructor
{
	head = nullptr;
	tail = nullptr;
}

void ItemList::addItems(Items^ items)//adding items to the list
{
	//if the list is empty
	if (head == nullptr)
	{
		//point the head and tail to the item object passed in
		head = items;
		tail = items;
	}

	//if the list is not empty
	else
	{
		//point the tail and its next to the item object passed in
		tail->Next = items;
		tail = items;
	}
}

void ItemList::deleteItems(Items^ itemsToDelete)//deleting the items from the list
{
	//if the object to be deleted is the head of the list
	if (itemsToDelete == head)
	{
		//if there is only one item in the list then set both the head and tail to be nothing
		Items^ index = head;
		if (index->Next == nullptr)
		{
			head = nullptr;
			tail = nullptr;
		}

		//if there is more items after the head of the list, move the head to its next
		else
		{
			head = head->Next;
		}
	}

	//if the object to be deleted is not the head
	else
	{
		//loop through the list till you reach the object to be deleted
		Items^ index = head;
		while (index->Next != itemsToDelete)
		{
			index = index->Next;
		}
		//get rid of the object by skipping over it
		index->Next = itemsToDelete->Next;
	}
}

void ItemList::drawToViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight)//drawing the items that is in the viewport to the form
{
	//looping through the list and calling the method
	Items^ index = head;
	while (index != nullptr)
	{
		index->drawInViewport(viewportPosition, viewportWidth, viewportHeight);
		index = index->Next;
	}
}

int ItemList::checkCollisionWithPlayer()//checking collsion with the player character
{
	int value = 0;
	Items^ index = head;
	//looping through the list and calling the method
	while (index != nullptr)
	{
		//if collison with player is true
		if (index->checkCollisionWithPlayer())
		{
			//if the item is the gold bar
			if (index->type == "Gold")
			{
				//add 100 points to the score
				value += index->value;
			}

			//if the item is the health potion
			if (index->type == "Health Potion")
			{
				//minus player's health by 10
				index->player->health += 10;
			}

			//delete the item that have collided with the player
			deleteItems(index);
		}
		index = index->Next;
	}
	return value;
}


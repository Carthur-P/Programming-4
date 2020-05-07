#include "EnemyList.h"

EnemyList::EnemyList()//contructor
{
	head = nullptr;
	tail = nullptr;
}

void EnemyList::addEnemy(Enemy^ enemy)//adding a new enemy character to the list
{
	//if the list is empty
	if (head == nullptr)
	{
		//point the head and tail to the enemy object passed in
		head = enemy;
		tail = enemy;
	}

	//if the list is not empty
	else
	{
		//point the tail and its next to the enemy object passed in
		tail->Next = enemy;
		tail = enemy;
	}
}

void EnemyList::deleteEnemy(Enemy^ enemyToDelete)//deleting the enemy character from the list
{
	//if the object to be deleted is the head of the list
	if (enemyToDelete == head)
	{
		//if there is only one item in the list then set both the head and tail to be nothing
		Enemy^ index = head;
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
		Enemy^ index = head;
		while (index->Next != enemyToDelete)
		{
			index = index->Next;
		}
		//get rid of the object by skipping over it
		index->Next = enemyToDelete->Next;
	}
}

void EnemyList::drawToViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight)//drawing the enemy that is in the viewport to the form
{
	//looping through the list and calling the method
	Enemy^ index = head;
	while (index != nullptr)
	{
		index->drawInViewport(viewportPosition, viewportWidth, viewportHeight);
		index = index->Next;
	}
}

void EnemyList::move(TileMap^ map)//moving the enemy 
{
	//looping through the list and calling the method
	Enemy^ index = head;
	while (index != nullptr)
	{
		index->setDirection();
		//checking to see if the tile is walkable before calling the move method
		if (index->checkWalkable(map) == true)
		{
			index->move();
		}
		index = index->Next;
	}
}

void EnemyList::checkCollisonWithPlayer()//checking enemy collsion with the player character
{
	//looping through the list and calling the method
	Enemy^ index = head;
	while (index != nullptr)
	{
		index->checkCollisionWithPlayer();
		index = index->Next;
	}
}



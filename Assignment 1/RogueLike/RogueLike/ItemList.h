#pragma once
#include "Items.h"

ref class ItemList
{
private:
	Items^ head;
	Items^ tail;

public:
	ItemList();

	void addItems(Items^ items);
	void deleteItems(Items^ itemsToDelete);
	void drawToViewport(Point^ viewportPosition, int viewportWidth, int viewportHeight);
	int checkCollisionWithPlayer();
};


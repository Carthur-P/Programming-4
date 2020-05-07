#include "GnomeController.h"

GnomeController::GnomeController(Graphics^ startCanvas, Random^ random, int startNumGnomes, int formWidth, int formHeight)//constructor
{
	numGonme = startNumGnomes;
	score = 0;
	gnomeArray = gcnew array<Gnome^>(numGonme);
	rand = random;
	for (int i = 0; i < numGonme; i++)
	{
		gnomeArray[i] = gcnew Gnome(startCanvas, rand->Next(formWidth), rand->Next(formHeight) + 30);
	}
}

void GnomeController::drawGnome(int indexGnome)//drawing the selected gnome onto the form
{
	gnomeArray[indexGnome]->draw();
}

void GnomeController::drawAllHitGnome()//drawing all the gnome that have been turned to a hamster onto the form
{
	for (int i = 0; i < gnomeArray->Length; i++)
	{
		if (gnomeArray[i]->getIsAHamster() == true)
		{
			gnomeArray[i]->draw();
		}
	}
}

void GnomeController::clearGnome()//erasing all the gnomes that have been drawn off the form
{
	for (int i = 0; i < gnomeArray->Length; i++)
	{
		gnomeArray[i]->erase();
	}
}

void GnomeController::hitAGnome(int indexGnome, int x, int y)//checking to see if the position of the mouse click is within the gnome image area
{
	if ((x >= gnomeArray[indexGnome]->getPositionX()) && (x <= gnomeArray[indexGnome]->getPositionX() + gnomeArray[indexGnome]->getGnomeImage()->Width) && (y >= gnomeArray[indexGnome]->getPositionY()) && (y <= gnomeArray[indexGnome]->getPositionY() + gnomeArray[indexGnome]->getGnomeImage()->Height))
	{
		gnomeArray[indexGnome]->hit();
		gnomeArray[indexGnome]->draw();
		score++;
	}
}

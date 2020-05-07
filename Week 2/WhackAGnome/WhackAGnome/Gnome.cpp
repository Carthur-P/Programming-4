#include "Gnome.h"

Gnome::Gnome(Graphics^ startCanvas, int startPositionX, int startPositonY)//constructor
{
	imagePath = "../ImageResources/gnome.jpg";
	gnomeImage = Image::FromFile(imagePath);
	canvas = startCanvas;
	isAHamster = false;
	positionX = startPositionX;
	positionY = startPositonY;
}

void Gnome::draw()//drawing gnome onto the form
{
	canvas->DrawImage(gnomeImage, positionX, positionY);
}

void Gnome::erase()//erasing the gnome from the form
{
	canvas->Clear(Color::White);
}

void Gnome::hit()//changing the gnome to a hamster
{
	imagePath = "../ImageResources/hamster.jpg";
	gnomeImage = Image::FromFile(imagePath);
	isAHamster = true;
}

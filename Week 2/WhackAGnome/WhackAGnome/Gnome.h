#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Gnome
{
private:
	Graphics^ canvas;
	Image^ gnomeImage;
	int positionX;
	int positionY;
	bool isAHamster;
	String^ imagePath;

public:
	Gnome(Graphics^ canvas, int positionX, int positionY);
	void draw();
	void erase();
	void hit();

	bool getIsAHamster() { return isAHamster; }
	void setIsAHamster(bool i) { isAHamster = i; }
	int getPositionX() { return positionX; }
	void setPositionX(int x) { positionX = x; }
	int getPositionY() { return positionY; }
	void setPositionY(int y) { positionY = y; }
	Image^ getGnomeImage() { return gnomeImage; }
	void setGnomeImage(Image^ image) { gnomeImage = image; }
};


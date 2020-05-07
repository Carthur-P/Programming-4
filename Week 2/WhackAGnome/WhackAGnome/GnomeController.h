#pragma once
#include "Gnome.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class GnomeController
{
private:
	Graphics^ canvas;
	array<Gnome^>^ gnomeArray;
	int numGonme;
	int score;
	Random^ rand;

public:
	GnomeController(Graphics^ graphics, Random^ rand, int startNumGnome, int formWidth, int formHeight);
	void drawGnome(int indexGnome);
	void drawAllHitGnome();
	void clearGnome();
	void hitAGnome(int indexGnome, int x, int y);

	int getScore() { return score; }
	void setScore(int num) { score = num; }
};


#pragma once
#include "Chicken.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class ChickenList
{
private:
	Chicken ^ head;
	Chicken^ tail;

public:
	ChickenList();

	void addChicken(Chicken^ chicken);
	void drawChickenToViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight);
	void moveAllChicken();
	void setAllChickenDirection();
	void updateAllChicken();
};


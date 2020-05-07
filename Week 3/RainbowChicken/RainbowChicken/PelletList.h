#pragma once
#include "Pellet.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class PelletList
{
private:
	Pellet^ head;
	Pellet^ tail;

public:
	PelletList();
	int countPellet();
	void moveAllPellet();
	void deleteAllPellet();
	void addPellet(Pellet^ pellet);
	void deleteDeadPellet(Pellet^ pelletToDelete);
	void drawAllPellet();
};


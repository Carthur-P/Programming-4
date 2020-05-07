#pragma once
#include "Wizard.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class WizardList
{
private:
	Wizard^ head;
	Wizard^ tail;

public:
	WizardList();

	void addWizard(Wizard^ chicken);
	void drawWizardToViewport(int viewportX, int viewportY, int viewportWidth, int viewportHeight);
	void updateAllWizard();
	Wizard^ checkCollision();
	void deleteWizard(Wizard^ wizardToDelete);
};


#pragma once
#include "Sprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Player : public Sprite
{
public:
	property int health;

	Player(Graphics^ canvas, Random^ rand, array<String^>^ movingFilePath, int formWidth, int formHeight);

	void moveOffCenter();
	virtual void setCollisionFrame() override;
};


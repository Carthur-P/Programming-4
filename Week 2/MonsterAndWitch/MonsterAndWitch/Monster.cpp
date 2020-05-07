#include "Monster.h"

using namespace System::Windows::Forms;
using namespace System;

Monster::Monster(String^ name)
{
	monsterName = gcnew String(name);
}

void Monster::speak()
{
	MessageBox::Show("I am a Monster! Roar! I am " + monsterName);
}



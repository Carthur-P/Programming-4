#include "Witch.h"

using namespace System::Windows::Forms;
using namespace System;

Witch::Witch(String^ name)
{
	witchName = gcnew String(name);
}

void Witch::speak()
{
	MessageBox::Show("I am a Witch! Hehehe! I am " + witchName);
}

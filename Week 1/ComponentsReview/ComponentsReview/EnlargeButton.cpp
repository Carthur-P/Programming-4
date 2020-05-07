#include "EnlargeButton.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ComponentsReview::EnlargeButton form;
	Application::Run(%form);
}

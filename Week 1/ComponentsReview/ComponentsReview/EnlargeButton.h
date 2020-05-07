/*Program name:			Component Review
* Project file name:    ComponentReview
* Author:               Carthur Pongpatimet
* Date:                 27/07/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a project that showcase the different functions that each form components is a capable of doing.

* Description:          Each forms showcase different component's functions which are all linked together in sequence with the next button. The form's name specify
						what function it is going to do for example the form 'EnlargeButton' will enlarge the button on each click.
*/

#pragma once
#include "TextToButton.h"

namespace ComponentsReview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EnlargeButton
	/// </summary>
	public ref class EnlargeButton : public System::Windows::Forms::Form
	{
	public:
		EnlargeButton(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EnlargeButton()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(101, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Next";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EnlargeButton::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(101, 78);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Enlarge";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EnlargeButton::button2_Click);
			// 
			// EnlargeButton
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 213);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"EnlargeButton";
			this->Text = L"Excercise 1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		TextToButton^ nxtForm = gcnew TextToButton();
		nxtForm->ShowDialog();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		button2->Height += 10;
		button2->Width += 10;

		if (button2->Right > ClientSize.Width)
		{
			button2->Text = "Too Big";
			button2->BackColor = Color::Red;
		}
	}

	};
}

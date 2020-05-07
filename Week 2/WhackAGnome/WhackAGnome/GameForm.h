/* Program name:		Whack A Gnome
* Project file name:    WhackAGnome
* Author:               Carthur Pongpatimet
* Date:                 03/08/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a whack a mole (whack a gnome) style game where the user will click on each gnomes that will appear in random positions.
						If the user is able to click on the gnome, the gnome will turn into a hamster and the user will be granted one score. The Game ends when
						all the gnome have been turned to hamster.

* Description:          Game Form - The form contains all the components that the user will interact with to play the game. This is also where the gnomes will appear
						for the user to click on.

						Gnome Controller - Act as a host for all the gnomes where all the the gnomes will be stored in an array and its methods called upon.

						Gnome - The actual gnome object which will draw itself and change its looks when the user click on it.
*
* Known bugs:           Gnomes sometimes slightly overlap each other since their location generation is random.
*/

#pragma once
#include "GnomeController.h"

namespace WhackAGnome {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{

	//User added variables
	private:
		Graphics^ canvas;
		Random^ rand;
		GnomeController^ gc;
		int startNumGnome;
		int indexGnome;

	public:
		GameForm(void)
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
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 800;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GameForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(463, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Score:";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(575, 319);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"GameForm";
			this->Text = L"Whack A Gnome";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::GameForm_MouseDown);
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {//form load event
		canvas = CreateGraphics();
		rand = gcnew Random();
		startNumGnome = 10;
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		if (gc->getScore() != startNumGnome)//game has not reach its end
		{
			gc->clearGnome();
			indexGnome = rand->Next(startNumGnome);
			gc->drawGnome(indexGnome);
			gc->drawAllHitGnome();
		}

		else//game has reach its end
		{
			timer1->Enabled = false;
			MessageBox::Show("You won! click the play button to play again");
			button1->Text = "Play";
		}
	}
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {//play button click event
		timer1->Enabled = true;
		gc = gcnew GnomeController(canvas, rand, startNumGnome, 500, 220);
		button1->Text = "Restart";
	}

	private: System::Void GameForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {//mouse click on the form event
		gc->hitAGnome(indexGnome, e->X, e->Y);
		label1->Text = "Score: " + gc->getScore();
	}
	};
}

/*Program name:			Chicken Shooting Rainbow
* Project file name:    RainbowChicken
* Author:               Carthur Pongpatimet
* Date:                 07/08/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a controllable chicken that can move side to side and shoot rainbow coloured pellet. The pellet will travel to the top of the form 
						and then disapear. A counter located on the top left corner will show how many pellet there is on the form.  

* Description:          Game Form - The form contains all the components that the user will interact with to play the game such and the chicken and the score label.

						Pellet List - This will act as a dynamic list class containing all the pellets. This will control the adding, drawing, moving and deleting
						of all the pellets on the form.

						Pellet - The actual pellet object which control attributes such as colour and size of the pellet.
*/

#pragma once
#include "PelletList.h"
#include "Pellet.h"

namespace RainbowChicken {

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
	public: 
		PelletList ^ pelletList;
		Pellet^ pellet;
		Graphics^ canvas;
		Random ^ rand;
		
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

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(161, 375);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(24, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 41);
			this->label1->TabIndex = 1;
			this->label1->Text = L"0";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(437, 446);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {//form load event
		timer1->Enabled = true;
		pictureBox1->Image = Image::FromFile("../ImageResources/chicken.gif");
		pelletList = gcnew PelletList();
		rand = gcnew Random();
		canvas = CreateGraphics();
	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {//key press event
		if (e->KeyCode == Keys::Left)//when left arrow key is press
		{
			pictureBox1->Left -= 10;
		}

		if (e->KeyCode == Keys::Right)//when right arrow key is press
		{
			pictureBox1->Left += 10;
		}

		if (e->KeyCode == Keys::Space)//when space bar is press
		{
			pellet = gcnew Pellet(canvas, rand, (pictureBox1->Left + (pictureBox1->Width / 2)), pictureBox1->Top);
			pelletList->addPellet(pellet);
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		canvas->Clear(Color::Black);
		pelletList->drawAllPellet();
		pelletList->moveAllPellet();
		label1->Text = System::Convert::ToString(pelletList->countPellet());//converting int to string
		pelletList->deleteAllPellet();
	}
};
}

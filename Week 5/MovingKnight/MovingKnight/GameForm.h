/*Program name:			Knight and Chicken
* Project file name:    MovingKnight
* Author:               Carthur Pongpatimet
* Date:                 21/08/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a controllable sprite animation and an uncontrollable sprite animation in a from of a walking knight
						and ten chicken NPC

* Description:          GameForm - The form contains all the components that will make the animation run and also allow the user to 
						control the knights walking direction using the arrow keys.

						Sprite - This is an abtract parent class of all the characters in the game. This class will hold all the common
						attributes and behavior that both the chicken and knight object have.

						Chicken - This is an uncontrollable character that will move randomly around the from.

						Knight - This is a controllable character that can be controlled by the user using the arrow keys. The user can
						only controll the direction that the character is moving in.

						ChickenList - This is a dynamic list that contains and control all the chicken characters in the game. There are
						ten chicken characters in total in the game.

Additional Features:	All the characters will not wander of the form as boundries checking was added
*/

#pragma once
#include "Chicken.h"
#include "ChickenList.h"
#include "Knight.h"

namespace MovingKnight {

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
		Graphics^ canvas;
		Graphics^ bufferedCanvas;
		Bitmap^ bufferedImage;
		Image^ background;
		Random^ rand;
		ChickenList^ cl;
		Knight^ knight;
		array<String^>^ imageFilePath;

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
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(753, 521);
			this->Name = L"GameForm";
			this->Text = L"Moving Knight";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {//form load event
		timer1->Enabled = true;
		rand = gcnew Random();
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		bufferedCanvas = Graphics::FromImage(bufferedImage);
		background = Image::FromFile("../imageResources/background.jpg");
		cl = gcnew ChickenList();
		knight = gcnew Knight(bufferedCanvas, imageFilePath = gcnew array<String^>(4) { "../imageResources/Knight Walk North.bmp",
			"../imageResources/Knight Walk East.bmp",
			"../imageResources/Knight Walk South.bmp",
			"../imageResources/Knight Walk West.bmp" });
		for (int i = 0; i < 10; i++)
		{
			cl->addChicken(gcnew Chicken(bufferedCanvas, rand, imageFilePath = gcnew array<String^>(4) { "../imageResources/Little Chicken Walk North.bmp", 
				"../imageResources/Little Chicken Walk East.bmp", 
				"../imageResources/Little Chicken Walk South.bmp", 
				"../imageResources/Little Chicken Walk West.bmp"}, ClientSize.Width, ClientSize.Height));
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		bufferedCanvas->DrawImage(background, 0, 0, ClientSize.Width, ClientSize.Height);//adding background 
		cl->updateAllChicken();
		cl->checkBoundries(ClientSize.Width, ClientSize.Height);
		cl->drawAllChicken();
		cl->moveAllChicken();
		cl->setAllChickenDirection();
		knight->updateFrame();
		knight->checkBoundries(ClientSize.Width, ClientSize.Height);
		knight->draw();
		knight->move();
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {//key down event to check what keyboard keys the user have pressed
		if (e->KeyCode == Keys::Up)
		{
			knight->setImageDirection(direction::NORTH);
		}

		if (e->KeyCode == Keys::Right)
		{
			knight->setImageDirection(direction::EAST);
		}

		if (e->KeyCode == Keys::Down)
		{
			knight->setImageDirection(direction::SOUTH);
		}

		if (e->KeyCode == Keys::Left)
		{
			knight->setImageDirection(direction::WEST);
		}
	}
	};
}

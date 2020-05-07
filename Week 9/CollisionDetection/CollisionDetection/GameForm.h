/*Program name:			Wizard to Chicken
* Project file name:    CollisionDetection
* Author:               Carthur Pongpatimet
* Date:                 14/09/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a program that will allow the user to control a knight using the arrow keys to move around
						the map. When the knight collides with the wizard, the wizard will trun into a chicken which will walk
						around the map.

* Description:          GameForm - The form contains all the components that will draw all the characters and map to the form and 
						will allow the user to control the knight character using the arrow keys. 

						Tile - This will contain the image of the terrain type for individual tiles that will make the map. This
						also contains the information about the tile being walkable or not.

						TileList - Contains an array that will hold all the different type of terrain that will be used to make the
						map.

						TileMap - This will setup the map itself which will allocate what terrain tile is gonna be place where to
						generate the whole map. This is done base on a two demensional array containing numbers that will represent
						what type of terrain is going to be use.

						Viewport - This is the class that will control what portion of the map is going to be displayed onto the
						screen.

						Sprite - This is the parent class of all the character in the game.

						Knight - This is a controllable character that can be controlled by the user using the arrow keys.

						Chicken - This is an uncontrollable character that will move randomly around the from. This character will 
						only appear after the knight have collisded with the wizard character.

						Wizard - This is an uncontrollable character that will appear randonmly throughout the map. When the knight
						character collides with it, it will dissapear and a chicken character will be created in its place.

						ChickenList - This is a dynamic list that contains and control all the chicken characters in the game. 

						WizardList - This is a dynamic list that contains and control all the wizard characters in the game. There are
						twenty wizard characters in total in the game.
*/

#pragma once
#include "Knight.h"
#include "Wizard.h"
#include "WizardList.h"
#include "ChickenList.h"
#include "Viewport.h"
#include "TileMap.h"

namespace CollisionDetection {

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
	private:
		Graphics^ canvas;
		Graphics^ bufferedCanvas;
		Bitmap^ bufferedImage;
		Random^ rand;
		Knight^ knight;
		Wizard^ wizard;
		Wizard^ changingWizard;
		WizardList^ wl;
		ChickenList^ cl;
		Viewport^ viewport;
		TileMap^ map;

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
			this->ClientSize = System::Drawing::Size(604, 446);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {//form load event
		timer1->Enabled = true;
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		bufferedCanvas = Graphics::FromImage(bufferedImage);
		rand = gcnew Random();
		map = gcnew TileMap(60, 60);
		viewport = gcnew Viewport(bufferedCanvas, map, gcnew Point(0, 0), 20, 15);
		wl = gcnew WizardList();
		cl = gcnew ChickenList();

		knight = gcnew Knight(bufferedCanvas, gcnew array<String^>(4) {
			"../imageResources/Knight Walk North.bmp",
			"../imageResources/Knight Walk East.bmp",
			"../imageResources/Knight Walk South.bmp",
			"../imageResources/Knight Walk West.bmp"
		}, ClientSize.Width, ClientSize.Height);

		for (int i = 0; i < 20; i++)
		{
			wl->addWizard(gcnew Wizard(bufferedCanvas, rand, gcnew String("../imageResources/Wizard.bmp"), map->numColumn * 32, map->numColumn * 32, knight));
		}

		viewport->move(knight->worldPosition->X, knight->worldPosition->Y);
		knight->updateFrame();
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		bufferedCanvas->Clear(Color::White);
		viewport->draw();
		knight->draw();
		wl->updateAllWizard();
		wl->drawWizardToViewport(viewport->viewportWorld->X, viewport->viewportWorld->Y, 20 * 32, 15 * 32);
		changingWizard = wl->checkCollision();

		if (changingWizard != nullptr)//when knight have collided with the wizard character
		{
			//chicken character is create in place of the wizard character
			cl->addChicken(gcnew Chicken(bufferedCanvas, rand, gcnew array<String^>(4) {
				"../imageResources/Little Chicken Walk North.bmp",
				"../imageResources/Little Chicken Walk East.bmp",
				"../imageResources/Little Chicken Walk South.bmp",
				"../imageResources/Little Chicken Walk West.bmp"
			}, *changingWizard->worldPosition));
		}

		cl->updateAllChicken();
		cl->drawChickenToViewport(viewport->viewportWorld->X, viewport->viewportWorld->Y, 20 * 32, 15 * 32);
		cl->setAllChickenDirection();
		cl->moveAllChicken();
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {//key down event
		if (e->KeyCode == Keys::Up && viewport->checkTopBoundrie() == false)//if top boundrie have not been reach
		{
			if (knight->position->Y > 150)//if the knight is of center
			{
				//move the knight up until it reach the center of the screen
				knight->setImageDirection(direction::NORTH);
				knight->updateFrame();
				knight->moveOffCenter();
			}
			else//when the knight is centered
			{
				//move the knight world position and viewport position while the knight will remain in the center
				knight->setImageDirection(direction::NORTH);
				knight->updateFrame();
				knight->move();
				viewport->move(knight->worldPosition->X, knight->worldPosition->Y);
			}
		}
		else if (e->KeyCode == Keys::Up && viewport->checkTopBoundrie() == true)//if top boundrie have been reach
		{
			//move the knight of center
			knight->setImageDirection(direction::NORTH);//have to set direction for when the user decide to move up again without reaching center
			knight->updateFrame();
			knight->moveOffCenter();
		}

		if (e->KeyCode == Keys::Right && viewport->checkRightBoundrie() == false)
		{
			if (knight->position->X < 260)
			{
				knight->setImageDirection(direction::EAST);
				knight->updateFrame();
				knight->moveOffCenter();
			}
			else
			{
				knight->setImageDirection(direction::EAST);
				knight->updateFrame();
				knight->move();
				viewport->move(knight->worldPosition->X, knight->worldPosition->Y);
			}
		}
		else if (e->KeyCode == Keys::Right && viewport->checkRightBoundrie() == true)
		{
			knight->setImageDirection(direction::EAST);
			knight->updateFrame();
			knight->moveOffCenter();
		}

		if (e->KeyCode == Keys::Down && viewport->checkBottomBoundrie() == false)
		{
			if (knight->position->Y < 150)
			{
				knight->setImageDirection(direction::SOUTH);
				knight->updateFrame();
				knight->moveOffCenter();
			}
			else
			{
				knight->setImageDirection(direction::SOUTH);
				knight->updateFrame();
				knight->move();
				viewport->move(knight->worldPosition->X, knight->worldPosition->Y);
			}
		}
		else if (e->KeyCode == Keys::Down && viewport->checkBottomBoundrie() == true)
		{
			knight->setImageDirection(direction::SOUTH);
			knight->updateFrame();
			knight->moveOffCenter();
		}

		if (e->KeyCode == Keys::Left && viewport->checkLeftBoundrie() == false)
		{
			if (knight->position->X > 260)
			{
				knight->setImageDirection(direction::WEST);
				knight->updateFrame();
				knight->moveOffCenter();
			}
			else
			{
				knight->setImageDirection(direction::WEST);
				knight->updateFrame();
				knight->move();
				viewport->move(knight->worldPosition->X, knight->worldPosition->Y);
			}
		}
		else if (e->KeyCode == Keys::Left && viewport->checkLeftBoundrie() == true)
		{
			knight->setImageDirection(direction::WEST);
			knight->updateFrame();
			knight->moveOffCenter();
		}
	}
};
}

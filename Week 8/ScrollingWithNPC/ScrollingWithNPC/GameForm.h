#pragma once
#include "TileMap.h"
#include "ChickenList.h"
#include "Chicken.h"
#include "Knight.h"
#include "viewport.h"

namespace ScrollingWithNPC {

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
		Graphics ^ canvas;
		Graphics^ bufferedCanvas;
		Bitmap^ bufferedImage;
		Random^ rand;
		TileMap^ tilemap;
		ChickenList^ chickenList;
		Knight^ knight;
		Viewport^ viewport;
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
	private: 
		System::ComponentModel::IContainer^  components;
		System::Windows::Forms::Timer^  timer1;

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
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = true;
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		bufferedCanvas = Graphics::FromImage(bufferedImage);
		rand = gcnew Random();
		tilemap = gcnew TileMap(60, 60);
		viewport = gcnew Viewport(bufferedCanvas, tilemap, 0, 0, 20, 15);
		chickenList = gcnew ChickenList();

		for (int i = 0; i < 50; i++)
		{
			chickenList->addChicken(gcnew Chicken(bufferedCanvas, rand, imageFilePath = gcnew array<String^>(4) {
				"../imageResources/Little Chicken Walk North.bmp",
				"../imageResources/Little Chicken Walk East.bmp",
				"../imageResources/Little Chicken Walk South.bmp",
				"../imageResources/Little Chicken Walk West.bmp"
			}, ClientSize.Width, ClientSize.Height, 60, 60));
		}

		knight = gcnew Knight(bufferedCanvas, imageFilePath = gcnew array<String^>(4) {
			"../imageResources/Knight Walk North.bmp",
			"../imageResources/Knight Walk East.bmp",
			"../imageResources/Knight Walk South.bmp",
			"../imageResources/Knight Walk West.bmp"
		}, ClientSize.Width, ClientSize.Height);

		knight->updateFrame();
		viewport->move(knight->worldPosition->X, knight->worldPosition->Y);
	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Up && viewport->checkTopBoundrie() == false)//if top boundrie have not been reach
		{
			if (knight->position->Y > 150)//if the knight is of center
			{
				//move the knight up until it reach the center of the screen
				knight->setImageDirection(direction::NORTH);
				knight->updateFrame();
				knight->moveOffCenter(0, -1);
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
			knight->moveOffCenter(0, -1);
		}

		if (e->KeyCode == Keys::Right && viewport->checkRightBoundrie() == false)
		{
			if (knight->position->X < 260)
			{
				knight->setImageDirection(direction::EAST);
				knight->updateFrame();
				knight->moveOffCenter(1, 0);
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
			knight->moveOffCenter(1, 0);
		}

		if (e->KeyCode == Keys::Down && viewport->checkBottomBoundrie() == false)
		{
			if (knight->position->Y < 150)
			{
				knight->setImageDirection(direction::SOUTH);
				knight->updateFrame();
				knight->moveOffCenter(0, 1);
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
			knight->moveOffCenter(0, 1);
		}

		if (e->KeyCode == Keys::Left && viewport->checkLeftBoundrie() == false)
		{
			if (knight->position->X > 260)
			{
				knight->setImageDirection(direction::WEST);
				knight->updateFrame();
				knight->moveOffCenter(-1, 0);
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
			knight->moveOffCenter(-1, 0);
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		bufferedCanvas->Clear(Color::White);
		viewport->draw();
		knight->draw();
		chickenList->setAllChickenDirection();
		chickenList->moveAllChicken();
		chickenList->updateAllChicken();
		chickenList->drawChickenToViewport(viewport->viewportWorldX, viewport->viewportWorldY, tilemap->numColumn * 32, tilemap->numRow *32);
		canvas->DrawImage(bufferedImage, 0, 0);
	}
};
}

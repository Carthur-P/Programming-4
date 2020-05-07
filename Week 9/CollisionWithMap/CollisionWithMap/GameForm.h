/*Program name:			Walking Chicken
* Project file name:    CollisionWithMap
* Author:               Carthur Pongpatimet
* Date:                 21/09/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a program that will allow the user to control a chicken character using the arrow keys 
						to move around the map. The chicken will not be able to walk over the flower tile but is allow 
						to move on everything else.

* Description:          GameForm - The form contains all the components and event that will draw and control the behavior
						of the chicken and the map.

						Tile - This will contain the image of the terrain type for individual tiles that will make the map.
						This also contains the information about the tile being walkable or not.

						TileList - Contains an array that will hold all the different type of terrain that will be used to
						make the map.

						TileMap - This will setup the map itself which will allocate what terrain tile is gonna be place
						where to generate the whole map. This is done base on a two demensional array containing numbers 
						that will represent what type of terrain is going to be use.

						Chicken - This is an controllable character that the user can control using the arrow keys. This
						character will not be able to move over the flower tile.
*/

#pragma once
#include "TileMap.h"
#include "Chicken.h"

namespace CollisionWithMap {

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
		TileMap^ map;
		Chicken^ chicken;

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
			this->ClientSize = System::Drawing::Size(640, 640);
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
		map = gcnew TileMap(bufferedCanvas, 20, 20);
		map->loadMap("../map.csv");
		
		chicken = gcnew Chicken(bufferedCanvas, gcnew array<String^>(4) {
			"../imageResources/Little Chicken Walk North.bmp",
			"../imageResources/Little Chicken Walk East.bmp",
			"../imageResources/Little Chicken Walk South.bmp",
			"../imageResources/Little Chicken Walk West.bmp"
		}, map, ClientSize.Width, ClientSize.Height);
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		bufferedCanvas->Clear(Color::White);
		map->draw();
		chicken->draw();
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {//key down event
		if (e->KeyCode == Keys::Up)
		{
			chicken->imageDirection = direction::NORTH;
			if (chicken->checkWalkable() == true)
			{
				chicken->move();
			}
		}

		if (e->KeyCode == Keys::Right)
		{
			chicken->imageDirection = direction::EAST;
			if (chicken->checkWalkable() == true)
			{
				chicken->move();
			}
		}

		if (e->KeyCode == Keys::Down)
		{
			chicken->imageDirection = direction::SOUTH;
			if (chicken->checkWalkable() == true)
			{
				chicken->move();
			}
		}

		if (e->KeyCode == Keys::Left)
		{
			chicken->imageDirection = direction::WEST;
			if (chicken->checkWalkable() == true)
			{
				chicken->move();
			}
		}
	}
	};
}

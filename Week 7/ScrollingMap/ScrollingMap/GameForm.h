/*Program name:			Moving Map
* Project file name:    ScrollingMap
* Author:               Carthur Pongpatimet
* Date:                 04/09/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a a program that will display portions of a pre determine map. This program will allow the
						user to move around and view different portions of the map using the arrow keys on the keyboard.

* Description:          GameForm - The form contains all the components that will draw the map to the form and allow the 
						user to control what portion of the map they see using the arrow keys.

						Tile - This will contain the image of the terrain type for individual tiles that will make the map.

						TileList - Contains an array that will hold all the different type of terrain that will be used to make the
						map.

						TileMap - This will setup the map itself which will allocate what terrain tile is gonna be place where to 
						generate the whole map. This is done base on a two demensional array containing numbers that will represent
						what type of terrain is going to be use.

						Viewport - This is the class that will control what portion of the map is going to be displayed onto the 
						screen.  
*/

#pragma once
#include "Viewport.h"
#include "TileMap.h"

namespace ScrollingMap {

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
		Graphics ^ canvas;
		Graphics^ bufferedCanvas;
		Bitmap^ bufferedImage;
		Viewport^ viewport;
		TileMap ^ tileMap;

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
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {//form load event
		timer1->Enabled = true;
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		bufferedCanvas = Graphics::FromImage(bufferedImage);
		tileMap = gcnew TileMap(60, 60);
		tileMap->loadMap("../map.csv");
		viewport = gcnew Viewport(bufferedCanvas, tileMap, 100, 100, 20, 15);
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		bufferedCanvas->Clear(Color::White);
		viewport->draw();
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {//key press event
		if (e->KeyCode == Keys::Up && viewport->checkTopBoundrie() == false)
		{
			viewport->move(0, -1);
		}

		if (e->KeyCode == Keys::Down && viewport->checkBottomBoundrie() == false)
		{
			viewport->move(0, 1);
		}

		if (e->KeyCode == Keys::Right && viewport->checkRightBoundrie() == false)
		{
			viewport->move(1, 0);
		}

		if (e->KeyCode == Keys::Left && viewport->checkLeftBoundrie() == false)
		{
			viewport->move(-1, 0);
		}
	}
	};
}

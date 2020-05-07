/*Program name:			Map Generation
* Project file name:    MapMaking
* Author:               Carthur Pongpatimet
* Date:                 28/08/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a program that will create a randomly generated map and a loaded in pre determine map. 

* Description:          GameForm - This will contain all the components that will generate the map including the two buttons that
						will allow the user to select between a random map and a pre loaded map.

						Tile - This will contain the image of the terrain type for individual tiles that will make the map.

						TileList - Contains an array that will hold all the different type of terrain that will be used to make the
						map.

						TileMap - This will setup the map itself which will allocate what terrain tile is gonna be place where to 
						generate the whole map. This is done base on a two demensional array containing numbers that will represent
						what type of terrain is going to be use.
*/

#pragma once
#include "TileList.h"
#include "TileMap.h"

namespace MapMaking {

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
		Graphics^ bufferedGraphics;
		Bitmap^ bufferedImage;
		Random^ rand;
		TileList^ tileList;
		TileMap ^ tileMap;
		int numRow;
	private: System::Windows::Forms::Button^  button2;
	public:
		int numColumn;

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
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: 
		System::Windows::Forms::Button^  button1;

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
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Random Map";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GameForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(120, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Load Map";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GameForm::button2_Click);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 640);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {//form load event
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		bufferedGraphics = Graphics::FromImage(bufferedImage);
		rand = gcnew Random();
		numRow = 20;
		numColumn = 20;
		tileMap = gcnew TileMap(bufferedGraphics, numRow, numColumn);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {//random generated map button click event
		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numColumn; j++)
			{
				tileMap->setMap(i, j, rand->Next(3));
			}
		}
		tileMap->draw();
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {//load pre made map button click event
		tileMap->loadMap("../map.csv");
		tileMap->draw();
		canvas->DrawImage(bufferedImage, 0, 0);
	}
};
}

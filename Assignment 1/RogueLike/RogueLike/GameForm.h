/*Program name:			Rogue Like Game
* Project file name:    RougueLike
* Author:               Carthur Pongpatimet
* Date:                 09/08/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a rougue like game which will allow the user to control a playable character using the arrow keys. The player will be able to
						move around a dungeon like map collecting gold to score points. There will also be NPC characters which are the alien enemy. The player will
						loose health if they collise with the enemy character. If the player's health reaches zero then the game will end by the player loosing.
						If the player collects all twenty gold bars then the player wins.

* Description:          GameForm - This is the game's screen which will display all the component of the game to the user. This will also act as a game manager class
						which will control what the game will do per one tick of the timer such as drawing ther player, drawing the enemy, drawing the map etc.

						Tile - This will contain the image of different types of terrain for individual tiles that will make up the map. This will also contains the
						information about the tile being walkable or not.

						TileList - Contains an array that will hold a collection of tile objects which is all the different type of terrain that will be used to make
						up the map.

						TileMap - This will setup the map itself which will allocate what terrain tile is gonna be place where to generate the whole map. This is done
						base on a two demensional array containing numbers that will represent what type of terrain is going to be use.

						Viewport - This is the class that will control what portion of the map is going to be displayed onto the screen. The portion that is shown will
						also adjust base on the postion of the player, keeping the player character in the center of the screen until the player reaches the edge of
						the map

						Sprite - This is the parent class of all the characters in the game which contains common methods that all the characters in the game have such
						as drawing, moving and updating frame etc.

						Player - Child class of the Sprite class. This is the controlable character class that the user can controll using the arrow keys to move
						around the map. The player can traverse around the map collecting gold bars to score points and health potions to gain health while avoiding
						the enemy character.

						Enemy - Child class of the Sprite class. This is an NPC character that will move around the map randomly. If this character collides with the
						player, the player will loose ten health points

						Items - This is the parent class for all the items in the game.

						Gold - Child class of the Items class. This is the item that the player will collect to score points. There will be twenty gold bar items
						scattered randomly around the map. Each gold bar will grants the player 100 points. The position of the gold items will change each time a
						new game is started.

						HealthPotions - Child class the the Items class. This is the items that will grant 10 health to the player when the player collects it. There
						will be 10 randomly scattered health postions around the map which will change each time a new game is started.

						EnemyList - This is the dynamic list class which will controll all the behavior of all the enemy characters in the game.

						ItemList - This is the dynamic list class that will controll all the behavior of all the items in the game.
*/

#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Gold.h"
#include "HealthPotion.h"
#include "TileMap.h"
#include "Viewport.h"
#include "EnemyList.h"
#include "ItemList.h"

namespace RogueLike {

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
		Player^ player;
		TileMap^ map;
		Viewport^ viewport;
		EnemyList^ el;
		ItemList^ il;
		int score;

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
		System::Windows::Forms::Timer^  timer1;
		System::Windows::Forms::Label^  label1;
		System::ComponentModel::IContainer^  components;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  label3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 80;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Score:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Health:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(151, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(323, 73);
			this->label3->TabIndex = 2;
			this->label3->Text = L"You Died!";
			this->label3->Visible = false;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 481);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {//game load event
		//setting up components and creating objects for the game
		timer1->Enabled = true;
		label3->Visible = false;
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		bufferedCanvas = Graphics::FromImage(bufferedImage);
		rand = gcnew Random();
		map = gcnew TileMap(80, 80);
		map->loadMap("../map.csv");
		el = gcnew EnemyList();
		il = gcnew ItemList();

		player = gcnew Player(bufferedCanvas, rand, gcnew array<String^>(4) {
		"../imageResources/playerMoveNorth.png",
		"../imageResources/playerMoveEast.png",
		"../imageResources/playerMoveSouth.png",
		"../imageResources/playerMoveWest.png"
		}, ClientSize.Width, ClientSize.Height);

		//looping through 20 times to create 20 enemies
		for(int i = 0; i < 20; i++)
		{
			el->addEnemy(gcnew Enemy(bufferedCanvas, rand, gcnew array<String^>(4) {
			"../imageResources/alienMoveNorth.png",
			"../imageResources/alienMoveEast.png",
			"../imageResources/alienMoveSouth.png",
			"../imageResources/alienMoveWest.png"
			}, map, ClientSize.Width, ClientSize.Height, map->numColumn * 32, map->numRow * 32, player));
		}

		//looping through 20 times to create 20 gold bars item
		for(int i = 0; i < 20; i++)
		{
			il->addItems(gcnew Gold(bufferedCanvas, rand, "../imageResources/gold.png", map, player, map->numColumn * 32, map->numRow * 32));
		}

		//looping through 10 times to create 10 health potion items
		for (int i = 0; i < 10; i++)
		{
			il->addItems(gcnew HealthPotion(bufferedCanvas, rand, "../imageResources/healthPotion.png", map, player, map->numColumn * 32, map->numRow * 32));
		}

		viewport = gcnew Viewport(bufferedCanvas, map, player->worldPosition, 20, 16);
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		bufferedCanvas->Clear(Color::White);
		
		//if player health is more than 0 then the game is still going 
		if (player->health > 0)
		{
			//all the method that makes the game run such as drawing and moving is called 
			viewport->draw();
			el->drawToViewport(viewport->viewportWorld, 20 * 32, 16 * 32);
			el->move(map);
			el->checkCollisonWithPlayer();
			il->drawToViewport(viewport->viewportWorld, 20 * 32, 16 * 32);
			score += il->checkCollisionWithPlayer();
			player->draw();
			label1->Text = "Score: " + score;
			label2->Text = "Health: " + player->health;
		}

		//if the player's health is 0 then the game have ended, the game over screen will display
		else
		{
			//drawing a black retangle the size of the form to the screen and making the label with the text "You Died" visible
			bufferedCanvas->FillRectangle(gcnew SolidBrush(Color::Black), 0, 0, ClientSize.Width, ClientSize.Height);
			label3->Visible = true;
		}

		//drawing the image that the buffered graphics have been drawing to to the screen. This means that only one image is draw to the screen minimising stutter
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Up)
		{
			//settig the sprite sheet image to the correct image base on the direction the character is moving in
			player->imageDirection = direction::NORTH;
			//if the tile is walkable then the player can move
			if (player->checkWalkable(map) == true)
			{
				//if the viewport has not reaches the edge of the map
				if (viewport->checkTopBoundrie() == false)
				{
					//if the player is current of centered then call the move method that will move its position variable
					if (player->position->Y > 226)
					{
						player->moveOffCenter();
					}
					
					//if the player is centered then call the move method that move its worldPosition variable and also the viewport move method
					else
					{
						player->move();
						viewport->move(0, -1);
					}
				}
				
				//if the viewport has reached the edge of the map, the player will start moving off centered
				else
				{
					player->moveOffCenter();
				}
			}
		}

		/*
		*************
		All the rest of the move method function exactly the same with the change being the sprite image sheet that is selected which is base on the directionn that the
		player is moving in
		*************
		*/

		if (e->KeyCode == Keys::Right)
		{
			player->imageDirection = direction::EAST;
			if (player->checkWalkable(map) == true)
			{
				if (viewport->checkRightBoundrie() == false)
				{
					if (player->position->X < 300)
					{
						player->moveOffCenter();
					}

					else
					{
						player->move();
						viewport->move(1, 0);
					}
				}

				else
				{
					player->moveOffCenter();
				}
			}
		}

		if (e->KeyCode == Keys::Down)
		{
			player->imageDirection = direction::SOUTH;
			if (player->checkWalkable(map) == true)
			{
				if (viewport->checkBottomBoundrie() == false)
				{
					if (player->position->Y < 226)
					{
						player->moveOffCenter();
					}

					else
					{
						player->move();
						viewport->move(0, 1);
					}
				}

				else
				{
					player->moveOffCenter();
				}
			}
		}

		if (e->KeyCode == Keys::Left)
		{
			player->imageDirection = direction::WEST;
			if (player->checkWalkable(map) == true)
			{
				if (viewport->checkLeftBoundrie() == false)
				{
					if (player->position->X > 300)
					{
						player->moveOffCenter();
					}

					else
					{
						player->move();
						viewport->move(-1, 0);
					}
				}

				else
				{
					player->moveOffCenter();
				}
			}
		}
	}
	};
}

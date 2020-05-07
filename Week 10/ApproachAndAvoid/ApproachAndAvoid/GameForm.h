#pragma once
#include "SpriteList.h"
#include "Blobbo.h"
#include "ApproachBot.h"

namespace ApproachAndAvoid {

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
		Bitmap^ background;
		Random^ rand;
		SpriteList^ sl;
		Blobbo^ blob;

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
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Move Blobbo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GameForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(864, 581);
			this->Controls->Add(this->button1);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = true;
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		background = gcnew Bitmap("../imageResources/outerSpace.jpg");
		bufferedCanvas = Graphics::FromImage(bufferedImage);
		rand = gcnew Random();
		sl = gcnew SpriteList();
		blob = gcnew Blobbo(bufferedCanvas, rand, gcnew Bitmap("../imageResources/blobbo.bmp"), 8, ClientSize.Width, ClientSize.Height);
		
		for (int i = 0; i < 10; i++)
		{
			sl->add(gcnew ApproachBot(bufferedCanvas, rand, gcnew Bitmap("../imageResources/redShip.bmp"), 40, ClientSize.Width, ClientSize.Height));
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		bufferedCanvas->DrawImage(background, 0, 0);
		blob->move();
		blob->draw();
		sl->draw();
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		blob->jump();
	}
	};
}

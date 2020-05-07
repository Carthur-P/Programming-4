/*Program name:			Blobbo In Space
* Project file name:    BlobboAnimation
* Author:               Carthur Pongpatimet
* Date:                 14/08/18
* Language:             C++
* Platform:             Microsoft Visual Studio 2017
*
* Purpose:              To create a sprite animation that can be drawn to the form. This animated character will then
						randomly move around the form.

* Description:          Animation Form - The form contains all the components that will make the animation run and also
						allow the user to add new animated characters to the form with a click of a button.

						Sprite List - This will act as a dynamic list class containing all the animated character blobbo.
						This will control the adding, drawing, and moving of all the blobbo character on the form.

						Sprite - The actual animated character class which control attributes such as what frame of the		
						sprite to show, what sprite to use, movement of the character etc.
*/

#pragma once
#include "SpriteList.h"
#include "Sprite.h"

namespace BlobboAnimation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AnimationForm
	/// </summary>
	public ref class AnimationForm : public System::Windows::Forms::Form
	{
	private: 
		SpriteList^ sl;
		Graphics^ canvas;
		Graphics^ bufferedCanvas;
		Random^ rand;
		Bitmap^ blobboSprite;
		Bitmap^ bufferedImage;
		Image^ background;
		int numFrame;

	public:
		AnimationForm(void)
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
		~AnimationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::Timer^  timer1;
		System::Windows::Forms::Button^  button1;
		System::ComponentModel::IContainer^  components;
		System::Windows::Forms::Button^  button2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AnimationForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &AnimationForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw A Blobbo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AnimationForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Draw Ten Blobbo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AnimationForm::button2_Click);
			// 
			// AnimationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(557, 445);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"AnimationForm";
			this->Text = L"Blobbo Animation";
			this->Load += gcnew System::EventHandler(this, &AnimationForm::AnimationForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AnimationForm_Load(System::Object^  sender, System::EventArgs^  e) {//form load event
		canvas = CreateGraphics();
		bufferedImage = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
		bufferedCanvas = Graphics::FromImage(bufferedImage);
		sl = gcnew SpriteList();
		rand = gcnew Random();
		blobboSprite = gcnew Bitmap(Image::FromFile("../ImageResources/BlobboMulti.bmp"));
		background = Image::FromFile("../ImageResources/outerSpace.jpg");
		numFrame = 8;
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {//timer tick event
		bufferedCanvas->DrawImage(background, 0, 0);
		sl->updateAllFrame();
		sl->drawAllSprite();
		sl->moveAllSprite();
		canvas->DrawImage(bufferedImage, 0, 0);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {//add a blobbo button click event
		timer1->Enabled = true;
		sl->addSprite(gcnew Sprite(bufferedCanvas, rand, blobboSprite, numFrame, ClientSize.Width, ClientSize.Height));
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {//add ten blobbo button click event
		timer1->Enabled = true;
		for (int i = 0; i < 10; i++)
		{
			sl->addSprite(gcnew Sprite(bufferedCanvas, rand, blobboSprite, numFrame, ClientSize.Width, ClientSize.Height));
		}
	}
};
}

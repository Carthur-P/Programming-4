#pragma once

namespace ComponentsReview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DrawingShapes
	/// </summary>
	public ref class DrawingShapes : public System::Windows::Forms::Form
	{

	private:
		Random^ rand;
		Graphics^ canvas;
		Brush^ color;

	public:
		DrawingShapes(void)
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
		~DrawingShapes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(103, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"End";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DrawingShapes::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(103, 70);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Draw";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &DrawingShapes::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &DrawingShapes::timer1_Tick);
			// 
			// DrawingShapes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"DrawingShapes";
			this->Text = L"Excercise 7";
			this->Load += gcnew System::EventHandler(this, &DrawingShapes::DrawingShapes_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button2->Text == "Draw")
		{
			button2->Text = "Stop";
			timer1->Enabled = true;
		}

		else
		{
			button2->Text = "Draw";
			timer1->Enabled = false;
		}	
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		color = gcnew SolidBrush(Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256)));
		canvas->FillEllipse(color, rand->Next(ClientSize.Width), rand->Next(ClientSize.Height),100, 100);
	}

	private: System::Void DrawingShapes_Load(System::Object^  sender, System::EventArgs^  e) {
		canvas = CreateGraphics();
		rand = gcnew Random();
	}
};
}

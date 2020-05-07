#pragma once

namespace Excercise2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::Windows::Forms::Button^  LeftButton;
	private: System::Windows::Forms::Button^  RightButton;
	private: System::Windows::Forms::Button^  button1;
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
			this->LeftButton = (gcnew System::Windows::Forms::Button());
			this->RightButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// LeftButton
			// 
			this->LeftButton->BackColor = System::Drawing::Color::Gainsboro;
			this->LeftButton->Location = System::Drawing::Point(117, 64);
			this->LeftButton->Name = L"LeftButton";
			this->LeftButton->Size = System::Drawing::Size(75, 23);
			this->LeftButton->TabIndex = 0;
			this->LeftButton->Text = L"Left";
			this->LeftButton->UseVisualStyleBackColor = false;
			// 
			// RightButton
			// 
			this->RightButton->Location = System::Drawing::Point(81, 103);
			this->RightButton->Name = L"RightButton";
			this->RightButton->Size = System::Drawing::Size(75, 23);
			this->RightButton->TabIndex = 1;
			this->RightButton->Text = L"Right";
			this->RightButton->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Go";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 146);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->RightButton);
			this->Controls->Add(this->LeftButton);
			this->Name = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		LeftButton->Left -= 5;
		RightButton->Left += 5;

		if (LeftButton->Left < 0)
		{
			timer1->Enabled = false;
			LeftButton->BackColor = Color::Green;
		}

		if (RightButton->Left + RightButton->Width > ClientSize.Width)
		{
			timer1->Enabled = false;
			RightButton->BackColor = Color::Green;
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		LeftButton->Location = Point(117, 64);
		RightButton->Location = Point(81, 103);
		LeftButton->BackColor = Color::Gainsboro;
		RightButton->BackColor = Color::Gainsboro;
		timer1->Enabled = true;
	}

	};
}

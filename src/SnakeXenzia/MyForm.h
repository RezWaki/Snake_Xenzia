#pragma once
//console includes
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "game.h"

namespace SnakeXenzia {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(12, 263);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Start";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			this->label1->MouseEnter += gcnew System::EventHandler(this, &MyForm::label1_MouseEnter);
			this->label1->MouseLeave += gcnew System::EventHandler(this, &MyForm::label1_MouseLeave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(184, 263);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Quit";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			this->label2->MouseEnter += gcnew System::EventHandler(this, &MyForm::label2_MouseEnter);
			this->label2->MouseLeave += gcnew System::EventHandler(this, &MyForm::label2_MouseLeave);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(240, 287);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowInTaskbar = false;
			this->Text = L"Snake Xenzia";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//command performer
		void Command( String^ cmd ){
			if( cmd == "/help" ){
				std::cout << "Info: blabla\n";
			}
		}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 Console::CursorVisible = false;
				 Console::Title = "Snake Xenzia console window";
				 system("color c");
				 std::cout << "Snake Xenzia winforms By RezWaki\nVisit: github.com/RezWaki for more fun stuff! :-)";
				 
			 }
	private: System::Void label1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 label1->ForeColor = System::Drawing::Color::Yellow; //set yellow color
			 }
	private: System::Void label1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 label1->ForeColor = System::Drawing::Color::Red; //set red color
			 }
	private: System::Void label2_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 label2->ForeColor = System::Drawing::Color::Yellow; //set yellow color
			 }
private: System::Void label2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 label2->ForeColor = System::Drawing::Color::Red; //set red color
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 game^ start = gcnew game();
			 start->Show();
		 }
};
}

#pragma once
#include <Windows.h>

namespace SnakeXenzia {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ game
	/// </summary>
	public ref class game : public System::Windows::Forms::Form
	{
	public:
		game(void)
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
		~game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Location = System::Drawing::Point(183, 139);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(10, 13);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Red;
			this->panel2->Location = System::Drawing::Point(183, 97);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(10, 13);
			this->panel2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(1, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Score:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(49, -4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"0";
			// 
			// game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"game";
			this->ShowInTaskbar = false;
			this->Text = L"Snake Xenzia";
			this->Load += gcnew System::EventHandler(this, &game::game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &game::game_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Drawing::Point snakeloc, fruitloc;
		int score;

		void Lose() {
			MessageBox::Show("You lose, OK - restart", "Snake Xenzia");
			score = 0; //score is 0
			snakeloc.X = score; //location is 0
			snakeloc.Y = score;
		}


	private: System::Void game_Load(System::Object^  sender, System::EventArgs^  e) {
				 snakeloc = panel1->Location;
				 fruitloc = panel2->Location;
				 //oldsnake = snakeloc; //useless oldsnake point
				 score = 0;
				 panel1->Height = 13;
			 }
	private: System::Void game_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if( e->KeyData == System::Windows::Forms::Keys::A ){
					 snakeloc.X -= 5; //snake moves left
				 }


				 if( e->KeyData == System::Windows::Forms::Keys::D ){
					 snakeloc.X += 5; //snake moves right
				 }


				 if( e->KeyData == System::Windows::Forms::Keys::W ){
					 snakeloc.Y -= 3; //snake moves forward (up)
				 }


				 if( e->KeyData == System::Windows::Forms::Keys::S ){
					 snakeloc.Y += 3; //snake moves backward (down) 
				 }

				 panel1->Location = snakeloc;

				 //collisions

				 if( snakeloc.X == fruitloc.X && snakeloc.Y == fruitloc.Y || snakeloc.X == fruitloc.X+1 && snakeloc.Y == fruitloc.Y+1 || snakeloc.X == fruitloc.X+2 && snakeloc.Y == fruitloc.Y+2 || snakeloc.X == fruitloc.X+3 && snakeloc.Y == fruitloc.Y+3 || snakeloc.X == fruitloc.X+6 && snakeloc.Y == fruitloc.Y+6 || snakeloc.X == fruitloc.X+5 && snakeloc.Y == fruitloc.Y+5 || snakeloc.X == fruitloc.X+4 && snakeloc.Y == fruitloc.Y+4 || snakeloc.X == fruitloc.X+7 && snakeloc.Y == fruitloc.Y+7 || snakeloc.X == fruitloc.X+8 && snakeloc.Y == fruitloc.Y+8 || snakeloc.X == fruitloc.X+panel1->Width+1 && snakeloc.Y == fruitloc.Y+panel1->Height+1 || snakeloc.X == fruitloc.X-1 && snakeloc.Y == fruitloc.Y-1 || snakeloc.X == fruitloc.X-2 && snakeloc.Y == fruitloc.Y-2 || snakeloc.X == fruitloc.X-3 && snakeloc.Y == fruitloc.Y-3 || snakeloc.X == fruitloc.X-6 && snakeloc.Y == fruitloc.Y-6 || snakeloc.X == fruitloc.X-5 && snakeloc.Y == fruitloc.Y-5 || snakeloc.X == fruitloc.X-4 && snakeloc.Y == fruitloc.Y-4 || snakeloc.X == fruitloc.X-7 && snakeloc.Y == fruitloc.Y-7 || snakeloc.X == fruitloc.X-8 && snakeloc.Y == fruitloc.Y-8 || snakeloc.X == fruitloc.X-panel1->Width-1 && snakeloc.Y == fruitloc.Y-panel1->Height-1 ){
					 fruitloc.X = rand() % 255;
					 fruitloc.Y = rand() % 255;
					 panel2->Location = fruitloc;
					 score++; // + one score point
					 label2->Text = System::Convert::ToString(score);
					 panel1->Height += 4; // our snake grows up :))
					 //oldsnake = snakeloc;
				 }

				 if( snakeloc.X < -4 || snakeloc.Y < -4 || snakeloc.X > 304 || snakeloc.Y > 300 ){ //if snake is out of bounds
					 Lose();
				 }

			 }
};
}

#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg){

Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);
Application::Run(gcnew SnakeXenzia::MyForm());
return 0;

}
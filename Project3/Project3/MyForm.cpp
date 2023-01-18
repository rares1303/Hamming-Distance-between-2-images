#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
// Namespace to nullify use of cv::function(); syntax


[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project3::MyForm frm;
	Application::Run(% frm);
}
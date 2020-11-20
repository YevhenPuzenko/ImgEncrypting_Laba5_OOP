#include "StartForm.h"
#include "EncryptForm.h"
#include "DecryptForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba5OOPimgEncrypting::StartForm form; //WinFormsTest - èìÿ âàøåãî ïðîåêòà
    Application::Run(% form);
}

System::Void Laba5OOPimgEncrypting::StartForm::EncryptButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    EncryptForm^ encr = gcnew EncryptForm();
    encr->Show();
    //this->Hide();
}

System::Void Laba5OOPimgEncrypting::StartForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void Laba5OOPimgEncrypting::StartForm::GitOpen_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::Diagnostics::Process::Start("https://github.com/YevhenPuzenko/ImgEncrypting_Laba5_OOP");
}

System::Void Laba5OOPimgEncrypting::StartForm::DecryptButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    DecryptForm^ decr = gcnew DecryptForm();
    decr->Show();
}

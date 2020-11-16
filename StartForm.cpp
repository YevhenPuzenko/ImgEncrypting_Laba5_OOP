#include "StartForm.h"
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
    return System::Void();
}

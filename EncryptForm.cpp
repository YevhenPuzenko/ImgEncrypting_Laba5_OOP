#include "EncryptForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void encrForm() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba5OOPimgEncrypting::EncryptForm eForm; 
    Application::Run(% eForm);
}
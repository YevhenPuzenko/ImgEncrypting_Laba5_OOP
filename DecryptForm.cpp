#include "DecryptForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void decrForm() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba5OOPimgEncrypting::DecryptForm form;
    Application::Run(% form);
}


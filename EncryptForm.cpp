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

System::Void Laba5OOPimgEncrypting::EncryptForm::EnterPicture_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenFileDialog^ dlg = gcnew OpenFileDialog();
    dlg->Filter = "AllFiles(*.*)|*.*|Bitmap(*.bmp)|*.bmp|Jpeg(*.jpg)|*.jpg;*.jpeg|PNG(*.png)|*.png";
    if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        ShowPicturePictureBox->Image = Image::FromFile((String^)dlg->FileName);
    }

}

System::Void Laba5OOPimgEncrypting::EncryptForm::CancellButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

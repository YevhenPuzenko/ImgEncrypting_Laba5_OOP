#include "EncryptForm.h"
#include "MyEncrypt.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void encrForm() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba5OOPimgEncrypting::EncryptForm form; 
    Application::Run(% form);
}

System::Void Laba5OOPimgEncrypting::EncryptForm::EnterPicture_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenFileDialog^ dlg = gcnew OpenFileDialog();
    dlg->Filter = "AllFiles(*.*)|*.*|Bitmap(*.bmp)|*.bmp|Jpeg(*.jpg)|*.jpg;*.jpeg|PNG(*.png)|*.png";
    if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        ShowPicturePictureBox->Image = Image::FromFile((String^)dlg->FileName);
        ImagePathLabel->Text = (String^)dlg->FileName;



    }

}

System::Void Laba5OOPimgEncrypting::EncryptForm::CancellButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void Laba5OOPimgEncrypting::EncryptForm::KeyGenButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyEncrypt temp;
    temp.keyGen();
    KeyTextBox->Text = temp.getKey();
}

System::Void Laba5OOPimgEncrypting::EncryptForm::EncryptButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    ShowPicturePictureBox->Image = Image::FromFile(ImagePathLabel->Text);//костыль что бы заново открыть картинку 
    
    
        


}





#include "EncryptForm.h"
#include "MyEncrypt.h"

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

System::Void Laba5OOPimgEncrypting::EncryptForm::KeyGenButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyEncrypt temp;
    temp.keyGen();
    KeyTextBox->Text = temp.getKey();
}

System::Void Laba5OOPimgEncrypting::EncryptForm::EncryptButton_Click(System::Object^ sender, System::EventArgs^ e)
{

    MyEncrypt encr;
    encr.setText(TextRichTextBox->Text);
    //KeyTextBox->Text = Convert::ToString(encr.strKeyToInt());
    encr.setKey(KeyTextBox->Text + "\0");

    Random ^rand = gcnew Random(encr.KeyToInt());

    Point* storage = new Point(encr.getText()->Length);//масив использованных пикселей
    for (size_t i = 0; i < encr.getText()->Length; i++)
    {
        int x, y;
        bool check = true;
        //шуруем сколько угодно пока не найдём свободный пиксель
        do {
            x = rand->Next(0, ShowPicturePictureBox->Image->Width);
            y = rand->Next(0, ShowPicturePictureBox->Image->Height);
            int count = 0;
            for (size_t j = 0; j < i; j++)
            {
                if (storage[j].X == x && storage[j].Y == y)//если уже натыкались на этот пиксель то ++
                   count++;
            }
            if (count == 0) check = false;
        } while (check);
        //записали уже использованный пиксель в масив 
        storage[i].X = x;
        storage[i].Y = y;
        //получаем пиксель
        Color^ thisColor = ((Bitmap^)ShowPicturePictureBox->Image)->GetPixel(x, y);
        //запись буквы в битовое представление цвета РГБ, 
        //для записи разбиваем байты символа на такие части R-3 G-2 B-3
        Color^ newColor;
        newColor->R = 

    }



}

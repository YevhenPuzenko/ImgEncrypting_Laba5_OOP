#include "DecryptForm.h"
#include "MyEncrypt.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void decrForm() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Laba5OOPimgEncrypting::DecryptForm form;
    Application::Run(% form);
}

System::Void Laba5OOPimgEncrypting::DecryptForm::EnterPictureButton_Click(System::Object^ sender, System::EventArgs^ e)
{

    OpenFileDialog^ dlg = gcnew OpenFileDialog();
    dlg->Filter = "AllFiles|*.bmp;*.jpg;*jpeg";
    if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        ShowPicturePictureBox->Image = Image::FromFile((String^)dlg->FileName);
        ImagePathLabel->Text = (String^)dlg->FileName;
        //((Bitmap^)ShowPicturePictureBox->Image)->SetPixel(20, 25, Color::FromArgb(0, 0, 0));


    }
}

System::Void Laba5OOPimgEncrypting::DecryptForm::CancellButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

struct Points {
    int x, y;
};

System::Void Laba5OOPimgEncrypting::DecryptForm::EncryptButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    ShowPicturePictureBox->Image = Image::FromFile(ImagePathLabel->Text);//костыль что бы заново открыть картинку 
    MyEncrypt decr;
    
    decr.setKey(KeyTextBox->Text);
    Random^ randomValGen = gcnew Random(decr.KeyToInt());

    int i = 0;//count sym
    String^ str;
    char sym;
    Points* busyPosPixels = new Points[decr.TextLength() + 1];
    do {

        //check if is unique pos x and y. If not unique - generate new pos
        bool uniqueStatus = true;
        unsigned int xPos, yPos;

        do {
            xPos = randomValGen->Next(0, ShowPicturePictureBox->Image->Width);
            yPos = randomValGen->Next(0, ShowPicturePictureBox->Image->Height);
            Color whiteCheck = ((Bitmap^)ShowPicturePictureBox->Image)->GetPixel(xPos, yPos);
            if (whiteCheck.R == NULL || whiteCheck.G == NULL || whiteCheck.B == NULL) break;
            for (size_t j = 0; j < i; j++)
                if (busyPosPixels[j].x == xPos && busyPosPixels[j].y == yPos)
                    uniqueStatus = false;
        } while (!uniqueStatus);
        i++;

        //add unique val in storage busyPosPixels
        busyPosPixels->x = xPos;
        busyPosPixels->y = yPos;

        Color thisPixel = ((Bitmap^)ShowPicturePictureBox->Image)->GetPixel(xPos, yPos);
        
        //to do ...
        //sym = ...
        //add new sym in str
        str += sym;
    } while (sym!='\0');
    decr.setText(str);
    TextRichTextBox->Text = str;

}

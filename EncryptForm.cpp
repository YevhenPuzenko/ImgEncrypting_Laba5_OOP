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
    dlg->Filter = "AllFiles|*.bmp;*.jpg;*jpeg";
    if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        ShowPicturePictureBox->Image = Image::FromFile((String^)dlg->FileName);
        ImagePathLabel->Text = (String^)dlg->FileName;
        //((Bitmap^)ShowPicturePictureBox->Image)->SetPixel(20, 25, Color::FromArgb(0, 0, 0));


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

struct Points {
    int x, y;
};

System::Void Laba5OOPimgEncrypting::EncryptForm::EncryptButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    ShowPicturePictureBox->Image = Image::FromFile(ImagePathLabel->Text);//костыль что бы заново открыть картинку 
    MyEncrypt encr;
    encr.setText(TextRichTextBox->Text);
    encr.setKey(KeyTextBox->Text);
    Random ^randomValGen = gcnew Random(encr.KeyToInt());
    
    if (ValidSizeToText(encr, ShowPicturePictureBox->Image->Width, ShowPicturePictureBox->Image->Height)) {
        //for(i<text.size)
        Points* busyPosPixels = new Points[encr.TextLength() + 1];
        for (size_t i = 0; i < encr.getText()->Length; i++)
        {

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

            //add unique val in storage busyPosPixels
            busyPosPixels->x = xPos;
            busyPosPixels->y = yPos;

            //pack char byte in RGB pixel(x,y)
            //pack sym(s) in new RGB. Where sym write in at this logic:
            //new byte = newR = rrrrrsss newG = ggggggss newB = bbbbbsss
            Color thisPixel = ((Bitmap^)ShowPicturePictureBox->Image)->GetPixel(xPos, yPos);

            unsigned char newR = ((thisPixel.R >> 3) << 3) | ((encr.getText()[i] >> 5) & 0b111);
            unsigned char newG = ((thisPixel.G >> 2) << 2) | ((encr.getText()[i] >> 3) & 0b11);
            unsigned char newB = ((thisPixel.B >> 3) << 3) | (encr.getText()[i] & 0b111);

            ((Bitmap^)ShowPicturePictureBox->Image)->SetPixel(xPos, yPos, Color::FromArgb(newR, newG, newB));
        }
        //save new picture
        SaveFileDialog^ savePicture = gcnew SaveFileDialog();
        savePicture->Title = "Save as...";
        savePicture->OverwritePrompt = true;   
        savePicture->CheckPathExists = true;
        savePicture->Filter = "BMP(*.BMP)|*.BMP";
        savePicture->FileName = "enc - ";
        if (savePicture->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            
            Bitmap^ bSave = ((Bitmap^)ShowPicturePictureBox->Image);
               bSave->Save(savePicture->FileName,System::Drawing::Imaging::ImageFormat::Bmp);
               
        }
        
    }
    
        


}





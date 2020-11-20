#include "DecryptForm.h"
#include "MyEncrypt.h"
#include<string.h>

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

	//int i = 0;//count sym
	string str;
	char sym = 0;
	Points* busyPosPixels = new Points[decr.TextLength() + 1];
	unsigned int xPos, yPos;
	xPos = randomValGen->Next(0, ShowPicturePictureBox->Image->Width);
	yPos = randomValGen->Next(0, ShowPicturePictureBox->Image->Height);
	Color thisPixel = ((Bitmap^)ShowPicturePictureBox->Image)->GetPixel(xPos, yPos);
	int len = (thisPixel.R & 0b00000111) << 5 | (thisPixel.G & 3) << 3 | (thisPixel.B & 7);

	for (size_t i = 0; i < len; i++)
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
		//i++;

		//add unique val in storage busyPosPixels
		busyPosPixels->x = xPos;
		busyPosPixels->y = yPos;

		Color thisPixel = ((Bitmap^)ShowPicturePictureBox->Image)->GetPixel(xPos, yPos);
		sym = (thisPixel.R & 0b00000111) << 5 | (thisPixel.G & 3) << 3 | (thisPixel.B & 7);
		
		//add new sym in str
		str+= sym;
	} 
	
	TextRichTextBox->Text = gcnew String(str.c_str());

}

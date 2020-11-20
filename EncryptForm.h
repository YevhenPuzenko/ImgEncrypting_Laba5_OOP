#pragma once

namespace Laba5OOPimgEncrypting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EncryptForm
	/// </summary>
	public ref class EncryptForm : public System::Windows::Forms::Form
	{
	public:
		EncryptForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EncryptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ EnterPictureButton;
	protected:

	private: System::Windows::Forms::Button^ KeyGenButton;
	private: System::Windows::Forms::TextBox^ KeyTextBox;
	protected:


	private: System::Windows::Forms::Button^ EncryptButton;


	private: System::Windows::Forms::PictureBox^ ShowPicturePictureBox;
	private: System::Windows::Forms::RichTextBox^ TextRichTextBox;
	private: System::Windows::Forms::Button^ CancellButton;

	private: System::Windows::Forms::Label^ ImagePathLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EnterPictureButton = (gcnew System::Windows::Forms::Button());
			this->KeyGenButton = (gcnew System::Windows::Forms::Button());
			this->KeyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EncryptButton = (gcnew System::Windows::Forms::Button());
			this->ShowPicturePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->TextRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->CancellButton = (gcnew System::Windows::Forms::Button());
			this->ImagePathLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ShowPicturePictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// EnterPictureButton
			// 
			this->EnterPictureButton->Location = System::Drawing::Point(194, 56);
			this->EnterPictureButton->Name = L"EnterPictureButton";
			this->EnterPictureButton->Size = System::Drawing::Size(176, 58);
			this->EnterPictureButton->TabIndex = 0;
			this->EnterPictureButton->Text = L"Enter picture";
			this->EnterPictureButton->UseVisualStyleBackColor = true;
			this->EnterPictureButton->Click += gcnew System::EventHandler(this, &EncryptForm::EnterPicture_Click);
			// 
			// KeyGenButton
			// 
			this->KeyGenButton->Location = System::Drawing::Point(12, 56);
			this->KeyGenButton->Name = L"KeyGenButton";
			this->KeyGenButton->Size = System::Drawing::Size(176, 58);
			this->KeyGenButton->TabIndex = 1;
			this->KeyGenButton->Text = L"Generate random key";
			this->KeyGenButton->UseVisualStyleBackColor = true;
			this->KeyGenButton->Click += gcnew System::EventHandler(this, &EncryptForm::KeyGenButton_Click);
			// 
			// KeyTextBox
			// 
			this->KeyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->KeyTextBox->Location = System::Drawing::Point(12, 12);
			this->KeyTextBox->Name = L"KeyTextBox";
			this->KeyTextBox->Size = System::Drawing::Size(358, 30);
			this->KeyTextBox->TabIndex = 2;
			this->KeyTextBox->Text = L"Input your key here";
			this->KeyTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EncryptForm::KeyTextBox_MouseClick);
			// 
			// EncryptButton
			// 
			this->EncryptButton->Location = System::Drawing::Point(12, 120);
			this->EncryptButton->Name = L"EncryptButton";
			this->EncryptButton->Size = System::Drawing::Size(176, 58);
			this->EncryptButton->TabIndex = 3;
			this->EncryptButton->Text = L"Encrypt";
			this->EncryptButton->UseVisualStyleBackColor = true;
			this->EncryptButton->Click += gcnew System::EventHandler(this, &EncryptForm::EncryptButton_Click);
			// 
			// ShowPicturePictureBox
			// 
			this->ShowPicturePictureBox->Location = System::Drawing::Point(12, 208);
			this->ShowPicturePictureBox->Name = L"ShowPicturePictureBox";
			this->ShowPicturePictureBox->Size = System::Drawing::Size(358, 366);
			this->ShowPicturePictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ShowPicturePictureBox->TabIndex = 5;
			this->ShowPicturePictureBox->TabStop = false;
			// 
			// TextRichTextBox
			// 
			this->TextRichTextBox->Location = System::Drawing::Point(376, 12);
			this->TextRichTextBox->Name = L"TextRichTextBox";
			this->TextRichTextBox->Size = System::Drawing::Size(434, 562);
			this->TextRichTextBox->TabIndex = 6;
			this->TextRichTextBox->Text = L"";
			// 
			// CancellButton
			// 
			this->CancellButton->Location = System::Drawing::Point(196, 120);
			this->CancellButton->Name = L"CancellButton";
			this->CancellButton->Size = System::Drawing::Size(173, 57);
			this->CancellButton->TabIndex = 4;
			this->CancellButton->Text = L"Cancell";
			this->CancellButton->UseVisualStyleBackColor = true;
			this->CancellButton->Click += gcnew System::EventHandler(this, &EncryptForm::CancellButton_Click);
			// 
			// ImagePathLabel
			// 
			this->ImagePathLabel->AutoSize = true;
			this->ImagePathLabel->Location = System::Drawing::Point(176, 181);
			this->ImagePathLabel->Name = L"ImagePathLabel";
			this->ImagePathLabel->Size = System::Drawing::Size(46, 17);
			this->ImagePathLabel->TabIndex = 8;
			this->ImagePathLabel->Text = L"label1";
			this->ImagePathLabel->Visible = false;
			// 
			// EncryptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(817, 582);
			this->Controls->Add(this->ImagePathLabel);
			this->Controls->Add(this->TextRichTextBox);
			this->Controls->Add(this->ShowPicturePictureBox);
			this->Controls->Add(this->CancellButton);
			this->Controls->Add(this->EncryptButton);
			this->Controls->Add(this->KeyTextBox);
			this->Controls->Add(this->KeyGenButton);
			this->Controls->Add(this->EnterPictureButton);
			this->Name = L"EncryptForm";
			this->Text = L"EncryptForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ShowPicturePictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EnterPicture_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void CancellButton_Click(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void KeyGenButton_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void EncryptButton_Click(System::Object^ sender, System::EventArgs^ e);






private: System::Void KeyTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

};
}

#pragma once
#include "MyString.h"
#include "MyEncrypt.h"

namespace Laba5OOPimgEncrypting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
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
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ EncryptButton;
	private: System::Windows::Forms::Button^ DecryptButton;
	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::PictureBox^ GitOpen;

	protected:


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->EncryptButton = (gcnew System::Windows::Forms::Button());
			this->DecryptButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->GitOpen = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GitOpen))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(58, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(872, 63);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Зашифруй свой текст в картинку!";
			// 
			// EncryptButton
			// 
			this->EncryptButton->Location = System::Drawing::Point(267, 203);
			this->EncryptButton->Name = L"EncryptButton";
			this->EncryptButton->Size = System::Drawing::Size(410, 70);
			this->EncryptButton->TabIndex = 1;
			this->EncryptButton->Text = L"Зашифровать";
			this->EncryptButton->UseVisualStyleBackColor = true;
			// 
			// DecryptButton
			// 
			this->DecryptButton->Location = System::Drawing::Point(267, 293);
			this->DecryptButton->Name = L"DecryptButton";
			this->DecryptButton->Size = System::Drawing::Size(410, 70);
			this->DecryptButton->TabIndex = 2;
			this->DecryptButton->Text = L"Розшифровать ";
			this->DecryptButton->UseVisualStyleBackColor = true;
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(267, 384);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(410, 70);
			this->ExitButton->TabIndex = 3;
			this->ExitButton->Text = L"Выйти";
			this->ExitButton->UseVisualStyleBackColor = true;
			// 
			// GitOpen
			// 
			this->GitOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GitOpen.Image")));
			this->GitOpen->Location = System::Drawing::Point(683, 385);
			this->GitOpen->Name = L"GitOpen";
			this->GitOpen->Size = System::Drawing::Size(69, 69);
			this->GitOpen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->GitOpen->TabIndex = 4;
			this->GitOpen->TabStop = false;
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 639);
			this->Controls->Add(this->GitOpen);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->DecryptButton);
			this->Controls->Add(this->EncryptButton);
			this->Controls->Add(this->label1);
			this->Name = L"StartForm";
			this->Text = L"ImgEncrypting";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GitOpen))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	
	};
}

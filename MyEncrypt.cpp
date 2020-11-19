#include "MyEncrypt.h"
#include <vcclr.h>

MyEncrypt::MyEncrypt()
{
	text = "";
	key = "";
}

MyEncrypt::MyEncrypt(MyString text, MyString key)
{
	this->text = text;
	this->key = key;
}

System::String^ MyEncrypt::getText()
{
	//System::String^ = gcnew System::String(text.getStr());
	return  gcnew System::String(text.getStr());
}

System::String^ MyEncrypt::getKey()
{
	return  gcnew System::String(key.getStr());
}

void MyEncrypt::setText(System::String^ str)
{
	for (size_t i = 0; i < str->Length; i++)
	{
		int temp = str[i];
		text = text + (char)temp;
	}

}

void MyEncrypt::setKey(System::String^ str)
{
	for (size_t i = 0; i < str->Length; i++)
	{
		int temp = str[i];
		key = key + (char)temp;
	}
}

void MyEncrypt::keyGen()
{
	System::Random^ random = gcnew System::Random();
	this->setKey((random->Next()%100000000000)+"");
}

long long int MyEncrypt::KeyToInt()
{
	return atoi(key.getStr());
}


#include"MyString.h"
#include <vcclr.h>
//#include <atlstr.h>
using System::String;
class MyEncrypt
{
private:
	MyString text;
	MyString key;
public:
	MyEncrypt();
	
	MyEncrypt(MyString text, MyString key);
		

	System::String^ getText();
	System::String^ getKey();
	void setText(String^ str);
	void setKey(String^ str);
	
	int TextLength();
	void keyGen();
	long long int KeyToInt();
	friend bool ValidSizeToText(MyEncrypt str, int width, int height);
	
};




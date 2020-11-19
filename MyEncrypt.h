
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
	void setText(System::String^ str);
	void setKey(System::String^ str);
	void keyGen();
	long long int KeyToInt();
	
};




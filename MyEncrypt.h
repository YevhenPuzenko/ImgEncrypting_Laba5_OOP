
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
	
	System::String^ getText() {
		//System::String^ =  gcnew System::String(text.getStr())
		return  gcnew System::String(text.getStr());
	}
	System::String^ getKey() {
		//System::String^ =  gcnew System::String(text.getStr())
		return  gcnew System::String(key.getStr());
	}
	void setText(System::String ^text1) {
		for (size_t i = 0; i < text1->Length; i++)
		{
			int temp = text1[i];
			text = text + (char)temp;
		}
	}
	void setKey(System::String^ key1) {
		for (size_t i = 0; i < key1->Length; i++)
		{
			int temp = key1[i];
			key = key + (char)temp;
		}
	}
	MyEncrypt(MyString text, MyString key) {
		this->text = text;
		this->key = key;
	}

	void keyGen() {
		System::Random^ random = gcnew System::Random();
		this->setKey((random->Next()%100000000000)+"");
	}
	long long int KeyToInt() {
		return atoi(key.getStr());
	}

	MyEncrypt() {
		text = "";
		key = "";
	}
	/*operator System::String ^ () {
		return gcnew System::String(text.getStr());
	}*/
	/*operator System::String ^ () {
		return gcnew System::String(w.getStr());
	}*/
	
	
	
	/*MyEncrypt(char*str) {
		y = str;
	}
	void PastNUll() {
		strcpy(y.getStr(), '\0');
	}
	*/


};




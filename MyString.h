#pragma once
#include <iostream>
using namespace std;
 class MyString
{
protected:
	char* str;
	int lenght;
private:

public:
	MyString();
	MyString(char);//
	MyString(char*);
	MyString(const char*);
	MyString(const MyString& str);

	~MyString() {
		delete[] str;
		lenght = 0;
	}

	char* getStr();
	int getLenght();
	void setStr(char*);
	void setLenght(int);


	 friend bool IsMore(MyString left, MyString right);
	 friend bool IsSmall(MyString left, MyString right);
	 friend bool IsEqual(MyString left, MyString right);

	MyString operator*(MyString);
	MyString operator+(MyString);
	MyString operator=(MyString);
	friend bool operator==(MyString, MyString);
	friend bool operator!=(MyString, MyString);
	friend bool operator<(MyString, MyString);
	friend bool operator>(MyString, MyString);
	friend bool operator<=(MyString, MyString);
	friend bool operator>=(MyString, MyString);



	ostream& ToPrint(ostream& os) const;
	MyString Copy(MyString);
	friend char* DestSymInStr(MyString, int, int);
	char* InsertIntoStr(MyString, int);
	char* SelectFromStr(int, int);
	int FirstEntranceInStr(char*);
	bool IsNumberUnsignedInt();
	int ToInt();
	//

	friend ostream& operator << (ostream& os, const MyString& str)
	{
		return str.ToPrint(os);
	}


	



};




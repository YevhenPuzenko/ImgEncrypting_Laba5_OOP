#include "MyString.h"
#include <iostream>

using namespace std;
#pragma warning(disable :4996)
bool IsMore(MyString left, MyString right)
{
	int pos = 0;
	do {

		if (int(left.str[pos]) > int(right.str[pos]))return true;// if int1 > int2 return true - first str is more
		if (int(left.str[pos]) < int(right.str[pos]))return false;// if int1 < int2 return false - second str is more
		pos++; // if int1 == int2; pos+1 - go to next int(char)
	} while (pos < left.lenght || pos < right.lenght);
}
bool IsEqual(MyString left, MyString right)
{
	int pos = 0;
	do {

		if (int(left.str[pos]) == int(right.str[pos]))pos++;
		if (int(left.str[pos]) != int(right.str[pos]))return false;
	} while (pos < left.lenght || pos < right.lenght);
	return true;
}
bool IsSmall(MyString left, MyString right)
{
	int pos = 0;
	do {

		if (int(left.str[pos]) < int(right.str[pos]))return true;// if int1 < int2 return true - second str is more
		if (int(left.str[pos]) > int(right.str[pos]))return false;// if int1 > int2 return false - first str is more
		pos++;// if int1 == int2; pos+1 - go to next int(char)
	} while (pos < left.lenght || pos < right.lenght);

}
MyString::MyString()
{
	str = NULL;
	lenght = 0;
}

MyString::MyString(char sym)
{
	lenght = sizeof(str);
	this->str = new char[lenght + 1];
	strcpy(this->str, &sym);
}

MyString::MyString(const char* str)
{
	lenght = strlen(str);
	this->str = new char[lenght + 1];
	strcpy(this->str, str);
}
MyString::MyString(char* str)
{
	lenght = strlen(str);
	this->str = new char[lenght + 1];
	strcpy(this->str, str);
}

MyString::MyString(const MyString& str)
{
	lenght = str.lenght;
	this->str = new char[lenght + 1];
	strcpy(this->str, str.str);

}

char* MyString::getStr()
{
	return str;
}

int MyString::getLenght()
{
	return lenght;
}

void MyString::setStr(char* str)
{
	setLenght(strlen(str));
	this->str = new char[lenght + 1];
	strcpy(this->str, str);
}

void MyString::setLenght(int lenght)
{
	this->lenght = lenght;
}

MyString MyString::operator*(MyString val)
{
	char* result;
	int pos = 0;
	lenght > val.lenght ? result = new char[lenght] : result = new char[val.lenght];

	for (size_t i = 0; i < lenght; i++)
	{
		for (size_t j = 0; j < val.lenght; j++)
		{
			if (str[i] == val.str[j])//ñìîòðèì íà ïîâòîðû çíà÷åíèé â èñõîäíûõ ÷àðàõ
			{
				int count = 0;
				for (size_t z = 0; z < pos; z++)//ñìîòðèì íà ïîâòîðû â êîíå÷íîì ÷àðå
				{
					if (str[i] == result[z])count++;
				}
				if (count == 0)result[pos++] = str[i];
			}
		}
	}
	result[pos] = '\0';//îòñåêàåì ëèøíåå, åñëè åñòü
	MyString res = MyString(result);
	cout << endl << res;
	return res;
}

MyString MyString::operator+(MyString val)
{
	char* temp = new char[lenght + val.lenght + 1];
	strcpy(temp, str);
	strcat(temp, val.str);
	MyString result = MyString(temp);

	delete[] temp;

	return result;
}

MyString MyString::operator=(MyString val)
{
	return Copy(val);
}

ostream& MyString::ToPrint(ostream& os) const
{
	cout << str;
	return os;
}

MyString MyString::Copy(MyString val)//
{
	MyString();
	str = new char[lenght + val.lenght + 1];
	strcpy(str, val.str);
	lenght = val.lenght;
	return MyString();
}



char* DestSymInStr(MyString val, int sym, int pos)
{

	char* temp = new char[val.lenght + 1];
	int step = 0;
	for (size_t i = 0; i < val.lenght; i++)
	{
		if (i == pos) i += sym;
		if (i < pos || i>pos) temp[step++] = val.str[i];
	}
	temp[step] = '\0';

	return temp;
}

char* MyString::InsertIntoStr(MyString val, int pos)
{
	char* res = new char[lenght + val.lenght + 1];
	for (size_t i = 0, j = 0; i < lenght + val.lenght + 1; i++)
	{
		if (i == pos) {
			for (size_t z = 0; z < strlen(val.str); z++)
			{
				res[i++] = val.str[z];
			}
		}
		if (i < pos || i>pos) res[i] = str[j++];

	}
	res[strlen(res)] = '\0';
	return res;
}

char* MyString::SelectFromStr(int n, int pos)
{
	char* res = new char[n + 1];
	for (size_t i = 0; i < n; i++)
	{
		res[i] = str[i + pos];
	}
	res[n] = '\0';
	return res;
}

int MyString::FirstEntranceInStr(char* val)//
{
	char* r = strstr(str, val);
	for (size_t i = 0; i < lenght; i++)
	{
		if (*r == *str) {
			return i;
		}
	}

}

bool MyString::IsNumberUnsignedInt()
{
	return ToInt() > 0 ? true : false;
}

int MyString::ToInt()
{
	return atoi(str);
}
bool operator==(MyString left, MyString right)
{
	return (left.lenght == right.lenght) ? IsEqual(left, right) : false;
}

bool operator!=(MyString left, MyString right)
{
	return (left.lenght != right.lenght) ? true : !(IsEqual(left, right));
}

bool operator<(MyString left, MyString right)
{
	return (left.lenght == right.lenght) ? IsSmall(left, right) : (left.lenght < right.lenght);
}

bool operator>(MyString left, MyString right)
{
	return (left.lenght == right.lenght) ? IsMore(left, right) : (left.lenght > right.lenght);
}

bool operator<=(MyString left, MyString right)
{
	return (left.lenght == right.lenght) ? IsSmall(left, right) || IsEqual(left, right) :
		(left.lenght <= right.lenght);
}

bool operator>=(MyString left, MyString right)
{
	return (left.lenght == right.lenght) ? IsMore(left, right) || IsEqual(left, right) :
		(left.lenght >= right.lenght);
}
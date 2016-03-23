#include "MyString.h"
#include <iostream>


MyString::MyString()
{
	_string = nullptr;
}

MyString::MyString(MyString & string) : MyString(string._string)
{
}

MyString::MyString(char * string)
{
	char* temp = new char[MyStrlen(string) + 1];

	strcpy(temp, string);
	
	_string = temp;
}

MyString::~MyString()
{
	if (_string != nullptr)
	{
		delete[] _string;
	}
}

char* MyString::GetString()
{
	return _string;
}

MyString MyString::ToLower()
{
	int length = MyStrlen(_string);

	MyString newString = *this;

	for (int i = 0; i < length; ++i)
	{
		if (newString._string[i] >= 'A' && newString._string[i] <= 'Z')
		{
			newString._string[i] -= ('A' - 'a');
		}
	}
	return newString;
}

MyString MyString::ToUpper()
{
	int length = MyStrlen(_string);
	MyString newString = *this;

	for (int i = 0; i < length; ++i)
	{
		if (newString._string[i] >= 'a' && newString._string[i] <= 'z')
		{
			newString._string[i] += ('A' - 'a');
		}
	}
	return newString;
}

int MyString::FindSubString(char* find)
{
	int fLength = MyStrlen(find);
	int length = MyStrlen(_string);

	for (int i = 0; i < length; ++i)
	{
		int counter = 0;
		while (_string[i] == find[counter])
		{
			++i;
			++counter;
			if (counter == fLength)
			{
				return i - counter;
			}
		}
	}
	return -1;
}

int MyString::FindSubString(MyString & find)
{
	int fLength = MyStrlen(find._string);
	int length = MyStrlen(_string);

	for (int i = 0; i < length; ++i)
	{
		int counter = 0;
		while (_string[i] == find._string[counter])
		{
			++i;
			++counter;
			if (counter == fLength)
			{
				return i - counter;
			}
		}
	}
	return -1;
}

int MyString::FindSubString(char * find, int index)
{
	int fLength = MyStrlen(find);
	int length = MyStrlen(_string);

	for (int i = index; i < length; ++i)
	{
		int counter = 0;
		while (_string[i] == find[counter])
		{
			++i;
			++counter;
			if (counter == fLength)
			{
				return i - counter;
			}
		}
	}
	return -1;
}

int MyString::FindSubString(MyString & find, int index)
{
	int fLength = MyStrlen(find._string);
	int length = MyStrlen(_string);

	for (int i = index; i < length; ++i)
	{
		int counter = 0;
		while (_string[i] == find._string[counter])
		{
			++i;
			++counter;
			if (counter == fLength)
			{
				return i - counter;
			}
		}
	}
	return -1;
}

void MyString::ReplaceSubString(char * find, char * replace)
{
	int fLength = MyStrlen(find);
	int rLength = MyStrlen(replace);
	int newLength = MyStrlen(_string) - fLength + rLength + 1;
	int index = FindSubString(find);

	char* temp = new char[newLength];

	for (int i = 0; i < newLength; ++i)
	{
		if (i < newLength && i < strlen(_string))
		{
			temp[i] = _string[i];
		}
	}

	temp[newLength - 1] = '\0';

	for (int i = index; i < newLength; ++i)
	{
		if (i + rLength < newLength && i + fLength < MyStrlen(_string)) // bounds for temp length and _string length
		{
			temp[i + rLength] = _string[i + fLength];
		}
		if (i - index < rLength) // bounds for length of replace._string
		{
			temp[i] = replace[i - index];
		}
	}

	temp[newLength - 1] = '\0';

	if (_string != nullptr)
	{
		delete[] _string;
	}

	_string = temp;

	if (FindSubString(find, index) != -1)
	{
		ReplaceSubString(find, replace);
	}
}

void MyString::ReplaceSubString(MyString & find, MyString & replace)
{
	int fLength = MyStrlen(find._string);
	int rLength = MyStrlen(replace._string);
	int newLength = MyStrlen(_string) - fLength + rLength + 1; 
	int index = FindSubString(find._string);

	char* temp = new char[newLength];

	for (int i = 0; i < newLength; ++i)
	{
		if (i < newLength && i < strlen(_string))
		{
			temp[i] = _string[i];
		}
	}
	temp[newLength - 1] = '\0';
	for (int i = index; i < newLength; ++i)
	{
		if (i + rLength < newLength && i + fLength < MyStrlen(_string)) // bounds for temp length and _string length
		{
			temp[i + rLength] = _string[i + fLength];
		}
		if (i - index < rLength) // bounds for length of replace._string
		{
			temp[i] = replace._string[i - index];
		}
	}
	
	temp[newLength - 1] = '\0';
	
	if (_string != nullptr)
	{
		delete[] _string;
	}

	_string = temp;

	if (FindSubString(find, index) != -1)
	{
		ReplaceSubString(find, replace);
	}
}

void MyString::SetString()
{
	std::string test;
	std::getline(std::cin, test);
	int length = MyStrlen(test);
	char* temp = new char[length + 1];
	for (int i = 0; i <= length; ++i)
	{
		temp[i] = test[i];
	}
	temp[length] = '\0';

	if (_string != nullptr)
	{
		delete[] _string;
	}

	_string = temp;
}

int MyString::MyStrlen()
{
	return strlen(_string);
}

int MyString::MyStrlen(char* withSpace)
{
	int index = 0;
	while (withSpace[index] != '\0')
	{
		++index;
	}
	return index;
}

int MyString::MyStrlen(MyString& withSpace)
{
	int index = 0;
	while (withSpace._string[index] != '\0')
	{
		++index;
	}
	return index;
}

int MyString::MyStrlen(std::string withSpace)
{
	int index = 0;
	while (withSpace[index] != '\0')
	{
		++index;
	}
	return index;
}

const char MyString::CharAt(int index)
{
	return _string[index];
}

bool MyString::Strcmp(char * string)
{
	return strcmp(_string, string);
}

bool MyString::Strcmp(MyString & string)
{
	return strcmp(_string, string._string);
}

void MyString::Append(char * string)
{
	char* temp = new char[MyStrlen(_string) + MyStrlen(string) + 1];

	strcpy(temp, _string);
	strcat(temp, string);

	if (_string != nullptr)
	{
		delete[] _string;
	}

	_string = temp;
}

void MyString::Append(MyString & string)
{
	char* temp = new char[MyStrlen(_string) + MyStrlen(string) + 1];

	strcpy(temp, _string);
	strcat(temp, string._string);

	if (_string != nullptr)
	{
		delete[] _string;
	}

	_string = temp;
}

void MyString::Prepend(char * string)
{
	char* temp = new char[MyStrlen(_string) + MyStrlen(string) + 1];

	strcpy(temp, string);
	strcat(temp, _string);

	if (_string != nullptr)
	{
		delete[] _string;
	}

	_string = temp;
}

void MyString::Prepend(MyString & string)
{
	char* temp = new char[MyStrlen(_string) + MyStrlen(string) + 1];

	strcpy(temp, string._string);
	strcat(temp, _string);

	if (_string != nullptr)
	{
		delete[] _string;
	}

	_string = temp;
}

void MyString::PrintString()
{
	if (_string != nullptr)
	{
		std::cout << _string << std::endl;
	}
	else
	{
		std::cout << "Why are you trying to print a nullptr?" << std::endl;
	}
}

bool MyString::operator==(char * compare)
{
	if (Strcmp(compare) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyString::operator==(MyString & compare)
{
	if (Strcmp(compare) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


std::istream & operator>>(std::istream & input, MyString & string)
{
	string.SetString();

	return input;
}

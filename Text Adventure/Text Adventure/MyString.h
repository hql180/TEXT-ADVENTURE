#pragma once
#include <string> // Only used for part (12) as storage and getline function


class MyString
{
public:
	MyString();

	MyString(MyString& string);

	MyString(char* string);

	~MyString();

	int MyStrlen(); // 1) The ability to query the string’s length, returning an integer

	int MyStrlen(char* withSpace); // Returns length of string with spaces included in count // Made because strlen seemed to not count spaces? But later found to count spaces
	// Input string to measure
	int MyStrlen(MyString& withSpace); 
	
	int MyStrlen(std::string withSpace); // Overload to work with string class string

	const char CharAt(int index); // 2) The ability to access a character at a certain index within the string class

	bool Strcmp(char* string); // 3) The ability to compare if the string is the same as another string class

	bool Strcmp(MyString& string);

	void Append(char* string); // 4) The ability to append one string to another

	void Append(MyString& string);

	void Prepend(char* string); // 5) The ability to prepend one string to another

	void Prepend(MyString& string);

	char* GetString(); // 6) The ability to return the string as a basic constant C-style string (const char*)

	MyString ToLower(); // 7) The ability to convert the string to a duplicate containing all lowercase letters

	MyString ToUpper(); // 8) The ability to convert the string to a duplicate containing all uppercase letters

	int FindSubString(char* find); // 9) The ability to find a sub-string within the string class

	int FindSubString(MyString& find);

	int FindSubString(char* find, int index); // 10) The ability to find a sub-string within the string class, starting from a certain index within the string

	int FindSubString(MyString& find, int index);

	void ReplaceSubString(char* find, char* replace);  // 11) The ability to replace a sub-string found within the string with a different sub-string
	
	void ReplaceSubString(MyString& find, MyString& replace);

	void SetString(); // 12) The ability to set the string to an input C-style string
		
	void PrintString();

private:
	char* _string;
};



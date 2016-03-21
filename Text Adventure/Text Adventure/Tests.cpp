#include <iostream>
#include <fstream>

#include "MyString.h"

using namespace std;

static int testNum = 0;
static int success = 0;

void testFunction(bool test, char* function, fstream& file)
{
	++testNum;
	if (test)
	{
		++success;
		file << "Test " << testNum << "\t" << function << "\tSuccessful\n";
	}
	else
	{
		file << "Test " << testNum << "\t" << function << "\tfailed\n";
	}
}

void runTests()
{
	fstream test;

	test.open("testlog.txt", ios::app);

	//The ability to query the string’s length, returning an integer
	MyString test1("four");
	testFunction(test1.MyStrlen() == 4, "Length", test);

	//	The ability to access a character at a certain index within the string class
	testFunction(test1.CharAt(2) == 'u', "CharAt", test);

	//	The ability to compare if the string is the same as another string class
	MyString test2("four");
	testFunction(test1.Strcmp(test2) == 0, "Strcmp", test);

	//	The ability to append one string to another
	MyString test3("ThErE");
	test1.Append(test3);
	testFunction(strcmp(test1.GetString(), "fourThErE") == 0, "Append", test);

	//	The ability to prepend one string to another
	test1.Prepend(test3);
	testFunction(strcmp(test1.GetString(), "ThErEfourThErE") == 0, "Prepend", test);

	//	The ability to return the string as a basic constant C - style string(const char*)
	testFunction(strcmp(test1.GetString(), "ThErEfourThErE") == 0, "GetStr", test);

	//	The ability to convert the string to a duplicate containing all lowercase letters
	MyString test4 = test1.ToLower();
	testFunction(strcmp(test4.GetString(), "therefourthere") == 0, "ToLower", test);

	//	The ability to convert the string to a duplicate containing all uppercase letters
	MyString test5 = test1.ToUpper();
	testFunction(strcmp(test5.GetString(), "THEREFOURTHERE") == 0, "ToUpper", test);

	//	The ability to find a sub - string within the string class
	testFunction(test1.FindSubString(test2) == 5, "FindSub", test);

	//	The ability to find a sub - string within the string class, starting from a certain index within the string
	testFunction(test1.FindSubString(test3, 3) == 9, "FinSub2", test);

	//	The ability to replace a sub - string found within the string with a different sub - string
	MyString test6("FiVe");
	test1.ReplaceSubString(test3, test6);
	testFunction(strcmp(test1.GetString(), "FiVefourFiVe") == 0, "ReplSub", test);

	MyString test7("AAAAA");
	MyString test8("B");
	MyString test9("A");

	test7.ReplaceSubString(test9, test8);
	testFunction(strcmp(test7.GetString(), "BBBBB") == 0, "ReplSub", test);

	//	The ability to set the string to an input C - style string
	char inputTest[20];
	MyString test10;

	cout << "Please type in 'plant' to test input\n";
	
	test7.SetString();
	testFunction(strcmp(test7.GetString(), "plant") == 0, "CSInput", test);

	float passRate = (float)success / testNum * 100;

	test << "Successful " << passRate << "%\n";
	test << "\n";

	test.close();
}

int notmain()
{
	runTests();

	

	system("pause");
    return 0;
}


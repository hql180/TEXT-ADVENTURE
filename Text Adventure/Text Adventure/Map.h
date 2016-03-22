#pragma once

#include <iostream>
#include <cstdlib>

#include "MyString.h"
#include "QuestionPool.h"



class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Run(int& currentMap);



protected:
	MyString _name;
	MyString _command;
	static int _G_ID;
	int _ID;
};


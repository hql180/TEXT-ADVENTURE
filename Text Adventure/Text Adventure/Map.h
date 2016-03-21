#pragma once

#include "MyString.h"


class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Input();

	virtual void Update(int& currentLocation);

	

protected:
	MyString _name;
	MyString _command;
	static int _G_ID;
	int _ID;

private:
};


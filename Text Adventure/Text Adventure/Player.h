#pragma once

#include "MyString.h"

class Player
{
public:
	Player();
	~Player();

	void InputCommand();

	void Update();

	char* GetName();

	MyString GetCommand();

private:
	MyString _name;
	MyString _command;
};


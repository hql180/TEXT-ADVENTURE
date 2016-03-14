#pragma once

#include "MyString.h"

class Player
{
public:
	Player();
	~Player();

	void InputCommand();

	void Update();

private:
	MyString _name;
	MyString _command;
};


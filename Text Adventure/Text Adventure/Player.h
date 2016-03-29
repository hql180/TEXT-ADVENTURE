#pragma once

#include "MyString.h"
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	void InputCommand();

	void Update();

	char* GetName();

	MyString GetCommand();

private:
	MyString _command;
};


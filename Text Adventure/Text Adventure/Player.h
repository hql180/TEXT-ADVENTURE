#pragma once

#include "MyString.h"
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	virtual void Attack(std::vector<Character*> list, int targetOveride);

private:
	MyString _command;
};


#pragma once

#include "MyString.h"
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	virtual void Attack(std::vector<Character*> list, int targetOveride);

	virtual void GainExp(double target);

	char* GetName();

private:
	int _gold;
};


#pragma once

#include "MyString.h"

class Character
{
public:
	Character();
	virtual ~Character();

protected:

private:
	MyString _name;
	int _health, _damage, _armour, _mana;
};


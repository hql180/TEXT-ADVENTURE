#pragma once

#include "MyString.h"

class Character
{
public:
	Character();
	virtual ~Character();

protected:
	MyString _name;
	int _health, _damage, _armour, _mana, _exp;
private:
	
};


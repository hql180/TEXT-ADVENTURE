#pragma once
#include <vector>

#include "MyString.h"

class Character
{
public:
	Character();
	virtual ~Character();

	virtual void Attack(std::vector<Character*> list, int targetOveride);

protected:
	MyString _name;
	int _health, _damage, _armour, _mana, _exp, _evasion;
private:
	
	
};


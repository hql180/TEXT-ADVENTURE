#pragma once
#include <vector>
#include <random>

#include "MyString.h"

class Character
{
public:
	Character();
	virtual ~Character();

	virtual void Attack(std::vector<Character*> list, int targetOveride);

	virtual void GainExp(double target);

protected:
	MyString _name;
	int _health, _damage, _armour, _mana, _evasion, _ID;
	double _exp;
	bool _isDead;

private:
	static int global_ID;
	
};


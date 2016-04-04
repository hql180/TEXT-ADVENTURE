#include "Character.h"



Character::Character()
{
	_health = 100;
	_damage = 20;
	_armour = 5;
	_mana = 30;
	_exp = 5;
	_evasion = 0;
}


Character::~Character()
{
}

void Character::Attack(std::vector<Character*> list, )
{
	int moreRand = rand() % 4 + 1;
	int adjustment = _damage *.3;
	int modifier;
	int target;

	for (int i = 0; i < moreRand; ++i)
	{
		target = rand() % list.size();
		modifier = (adjustment * 2) + 1;
	}
		
	int damage = (_damage - adjustment) + modifier - list[target]->_armour;
	if (damage < 1)
	{
		damage = 1;
	}

	list[target]->_health -= damage;
}



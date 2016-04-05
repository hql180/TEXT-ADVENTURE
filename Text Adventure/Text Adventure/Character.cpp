#include "Character.h"

int Character::global_ID = 0;

Character::Character()
{
	_health = 100;
	_damage = 20;
	_armour = 5;
	_mana = 30;
	_exp = 5;
	_evasion = 0;
	_ID = global_ID++;
	_isDead = false;
}


Character::~Character()
{
}

void Character::Attack(std::vector<Character*> list, int targetOveride)
{
	int adjustment = _damage *.3;
	int target;
	int hitRate = 20;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> range(0, adjustment);
	std::uniform_int_distribution<> targetChoice(0, list.size() - 1);
	std::uniform_int_distribution<> hitOrMiss(1, 20);
	
	int modifier = range(gen);

	if (targetOveride == -1)
	{
		target = targetChoice(gen);
		while (list[target]->_isDead)
		{
			target = targetChoice(gen);
		}
	}
	else
	{
		target = targetOveride;
		
	}
	
	hitRate -= list[target]->_evasion;

	if (!list[target]->_isDead)
	{
		if (hitRate >= hitOrMiss(gen))
		{
			int damage = (_damage - adjustment) + modifier - list[target]->_armour;
			if (damage < 1)
			{
				damage = 1;
			}

			list[target]->_health -= damage;
			std::cout << _name.GetString() << " attacks " << list[target]->_name.GetString() << " for " << damage << " damage ";

			if (list[target]->_health < 1)
			{
				std::cout << "killing it.\n";
				list[target]->_isDead = true;
				GainExp(list[target]->_exp);
			}
			std::cout << "\n";
		}
		else
		{
			std::cout << list[target]->_name.GetString() << " dodged " << _name.GetString() << "'s attack.\n";
		}
	}
	else
	{
		std::cout << _name.GetString() << " is trying to attack a dead body\n";
	}
}

void Character::GainExp(double target)
{
	_exp += ((double)1 / 3 * target);
}



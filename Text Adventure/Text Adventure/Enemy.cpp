#include "Enemy.h"



Enemy::Enemy() : Character()
{
	_health = 100;
	_damage = 20;
	_armour = 5;
	_mana = 30;
	_exp = 5;
	_evasion = 0;
	_isDead = false;
}


Enemy::~Enemy()
{
}

void Enemy::AddModifier()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> mod(0, 20);

	int modifier = mod(gen);

	switch (modifier)
	{
	case 0:
		_name.Append("Legendary ");
		_health *= 2;
		_damage *= 2;
		_armour *= 2;
		_mana *= 2;
		_exp *= 2;
		_evasion *= 2;
		break;
	case 1:
		_name.Append("Mythical ");
		_health *= 1.5;
		_damage *= 1.5;
		_armour *= 1.5;
		_mana *= 1.5;
		_exp *= 1.5;
		_evasion *= 1.5;
		break;
	case 2:
		_name.Append("Weakened ");
		_health *= .5;
		_damage *= .5;
		_armour *= .5;
		_mana *= .5;
		_evasion *= .5;
		break;
	default:
		break;
	}

}

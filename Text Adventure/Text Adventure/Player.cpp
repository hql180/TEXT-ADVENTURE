#include <iostream>

#include "Player.h"



Player::Player() : Character()
{
	std::cout << "Please input your name: ";
	_name.SetString();
	_gold = 0;
	_exp = 0;
	_health *= 1.5f;
	_damage *= 1.5f;
	_armour *= 1.5f;
	_mana *= 1.5f;
	_evasion = 1;
}

Player::~Player()
{
}

void Player::Attack(std::vector<Character*> list, int targetOveride)
{
	Character::Attack(list, targetOveride);
}

void Player::GainExp(double target)
{
	Character::GainExp(target * 1.5f);
	_gold = target*7.5f;
}

char * Player::GetName()
{
	return _name.GetString();
}




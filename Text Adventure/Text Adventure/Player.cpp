#include <iostream>

#include "Player.h"



Player::Player() : Character()
{
	std::cout << "Please input your name: ";
	_name.SetString();
}

Player::~Player()
{
}

void Player::Attack(std::vector<Character*> list, int targetOveride)
{
	Character::Attack(list, targetOveride);
}




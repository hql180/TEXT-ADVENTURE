#include <iostream>

#include "Player.h"



Player::Player()
{
	std::cout << "Please input your name: ";
	_name.SetString();
}


Player::~Player()
{
}

void Player::InputCommand()
{
	_command.SetString();
}

void Player::Update()
{

}

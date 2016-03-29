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

void Player::InputCommand()
{
	_command.SetString();
}

void Player::Update()
{

}

char* Player::GetName()
{
	if (_name.GetString() != nullptr)
	{
		return _name.GetString();
	}
}

MyString Player::GetCommand()
{
	return _command.ToLower();
}



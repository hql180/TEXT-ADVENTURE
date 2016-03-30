#include "Stage2.h"



Stage2::Stage2()
{
}


Stage2::~Stage2()
{
}

void Stage2::Run(int & currentMap, Player & player)
{
	if (!_intro)
	{
		std::cout << "As you step though the door, you are suddenly surrounded\n";
		std::cout << "by dozens of crab people who immediately apprehend you.\n";
		std::cout << "They lead you to their boss who says:\n";
		std::cout << "Hahaha, foolish huu-man you have made it just in time to\n";
		std::cout << "take part in our Grand Celebration to mark our official attack\n";
		std::cout << "on the huu-man race. You will take part in a gladiator battle\n";
		std::cout << "to show our people how feeble the huu-man race is. Hahaha.\n";
		std::cout << "we'll even provide you with weapons and armour to show our soilders\n";
		std::cout << "we can crush you in our claws even in a fair fight. Hahaha.\n";
		std::cout << "Go now you have one week to prepare for the Grand Celebration!\n\n";
		_intro = true;
	}
	else
	{
		std::cout << "You are currently in the collosseum hypogeum\n";
		RequestCommand();
		if (_command.ToLower() == "n" || _command.ToLower() == "north")
		{

		}
		else if (_command.ToLower() == "e" || _command.ToLower() == "east")
		{

		}
		else if (_command.ToLower() == "s" || _command.ToLower() == "south")
		{

		}
		else if (_command.ToLower() == "w" || _command.ToLower() == "west")
		{
		
		}
		else
		{
			std::cout << "Invalid command.\n";
		}
	}
}

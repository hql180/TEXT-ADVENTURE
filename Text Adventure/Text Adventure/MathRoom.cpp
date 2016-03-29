#include "MathRoom.h"



MathRoom::MathRoom()
{
}


MathRoom::~MathRoom()
{
}

void MathRoom::Run(int & currentMap, Player & player)
{
	if (!_gotKey)
	{
		std::cout << "You walk inside the room and find another wall which says\n";
		std::cout << "'" << _mathQuestion.GetQuestion() << "'\n";
		while (!_solved)
		{
			std::cout << "Please input command\n";
			
			//int answer;
			std::cin >> _command;
			_command.PrintString();
			if (_mathQuestion.CheckAnswer(_command))
			{
				_solved = true;
			}
			else
			{
				std::cout << "Incorrect answer. Please try again\n";
			}
		}
		std::cout << "A Steel Key drops out from the wall upon hearing your answer\n";
		while (!_gotKey)
		{
			std::cout << "Please input command\n";
			std::cin >> _command;
			MyString tempcommand = _command.ToLower();
			if (tempcommand.FindSubString("take") || tempcommand.FindSubString("get"))
			{
				ObtainKey();
			}
			else
			{
				std::cout << "Invalid command. Please try again\n";
			}
		}
	}
	else
	{
		std::cout << "You are in the room where you got the Steel Key from\n";
		RequestCommand();
		if (_command.ToLower() == "n" || _command.ToLower() == "north" || _command.ToLower() == "s" || _command.ToLower() == "south")
		{
			std::cout << "It's just a wall\n";
		}
		else if (_command.ToLower() == "w" || _command.ToLower() == "west")
		{
			std::cout << "It's that weird maths wall\n";
		}
		else if (_command.ToLower() == "e" || _command.ToLower() == "east")
		{
			std::cout << "You exit the weird maths room\n";
			currentMap = _mapName::STAGE1; // Back to stage1
		}
		else
		{
			std::cout << "Invalid command\n";
		}
	}
}

void MathRoom::ObtainKey()
{
	Stage1::ObtainKey();
	_gotKey = true;
	std::cout << "You picked up the Steel Key\n";
}

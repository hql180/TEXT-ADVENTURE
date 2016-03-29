#include "RiddleRoom.h"


RiddleRoom::RiddleRoom() : Stage1()
{
}


RiddleRoom::~RiddleRoom()
{
}

void RiddleRoom::Run(int & currentMap, Player& player) // Came from stage1
{
	if (CheckKeys() < 1)
	{
		std::cout << "Upon entering the room you see a wall with some ancient mystical text written on it\n";
		std::cout << "It reads '" << riddle.GetQuestion() << "'\n";
	}
	else
	{
		std::cout << "This is the room where you got the stone key from\n";
		while (currentMap == GetID())
		{
			RequestCommand();
			if (_command.ToLower() == "north" || _command.ToLower() == "n")
			{
				std::cout << "There's nothing there buddy. It's just a cave wall.\n";
			}
			else if (_command.ToLower() == "east" || _command.ToLower() == "e")
			{
				std::cout << "It's the overly dramatic wall where you got the stone key from.\n";
			}
			else if (_command.ToLower() == "west" || _command.ToLower() == "w")
			{
				std::cout << "You exited the the eastern riddle room and return to the main room.\n";
				currentMap = _mapName::STAGE1; // Moving back to stage1
			}
			else if (_command.ToLower() == "south" || _command.ToLower() == "s")
			{
				std::cout << "There's nothing there buddy. It's just a cave wall.\n";
			}
			else
			{
				std::cout << "Invalid command\n";
				std::cout << "Please re-enter command\n";
			}
		}
	}
	while (!riddle.CheckSolved())
	{
		std::cout << "Please input answer\n";
		std::cin >> _command;
		if (!riddle.CheckAnswer(_command))
		{
			std::cout << "Incorrect answer please try again\n";
		}
	}
	while (riddle.CheckSolved() && !_gotKey)
	{
		std::cout << "Having seen that you have comprehended the profundity of its ancient enigmatic puzzle\n";
		std::cout << "The mysterious spirits of this riddle room causes a stone key to be birthed from the wall\n";
		while (!_gotKey)
		{
			std::cin >> _command;
			if (_command.ToLower() == "get key" || _command.ToLower() == "take key" || _command.ToLower() == "pick up key")
			{
				std::cout << "You picked up the key\n";
				ObtainKey();
				
			}
			else
			{
				std::cout << "Invalid Command\n";
			}
		}
		while (currentMap == GetID())
		{
			RequestCommand();
			if (_command.ToLower() == "north" || _command.ToLower() == "n")
			{
				std::cout << "There's nothing there buddy. It's just a cave wall.\n";			
			}
			else if (_command.ToLower() == "east" || _command.ToLower() == "e")
			{
				std::cout << "It's the overly dramatic wall where you got the stone key from.\n";
			}
			else if (_command.ToLower() == "west" || _command.ToLower() == "w")
			{
				std::cout << "You exited the the eastern riddle room and return to the main room.\n";
				currentMap = 0; // Moving back to stage1
			}
			else if (_command.ToLower() == "south" || _command.ToLower() == "s")
			{
				std::cout << "There's nothing there buddy. It's just a cave wall.\n";
			}
			else
			{
				std::cout << "Invalid command\n";
				std::cout << "Please re-enter command\n";
			}
		}
	}
	
}

void RiddleRoom::ObtainKey()
{
	Stage1::ObtainKey();
	_gotKey = true;
}


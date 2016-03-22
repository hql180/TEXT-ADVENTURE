

#include "Stage1.h"



Stage1::Stage1()
{
	
}


Stage1::~Stage1()
{
}

void Stage1::Run(int & currentMap)
{
	
	std::cout << "Please input command (North, East, West, South, N, E, W, S)\n";
	std::cin >> _command;


	if (_command.ToLower() == "north" || _command.ToLower() == "n")
	{
		std::cout << "You walk north until you enter a dimly lit cavern with 3 doors\n";
		std::cout << "One to the East, one to the North and one to the south\n";
		while (currentMap == 0)
		{
			std::cin >> _command;
			if (_command.ToLower() == "north" || _command.ToLower() == "n")
			{
				if (CheckKeys() < 2)
				{
					std::cout << "The door is locked. Looks like it requires two keys to open.\n";
				}
				else
				{
					std::cout << "You used the key to unlock the door\n";
					currentMap = 0;
					std::cout << "\n\nfixfixfix\n\n";
				}
			}
			else if (_command.ToLower() == "east" || _command.ToLower() == "e")
			{
				std::cout << "You open the door to the East and enter.\n";
				currentMap = 1; // To RiddleRoom
			}
			else if (_command.ToLower() == "west" || _command.ToLower() == "w")
			{
				std::cout << "room1\n";
			}
			else if (_command.ToLower() == "south" || _command.ToLower() == "s")
			{
				std::cout << "current room 1\n";
			}
			else
			{
				std::cout << "Invalid command\n";
				std::cout << "Please re-enter command\n";
			}
		}
	}
	else if (_command.ToLower() == "east" || _command.ToLower() == "e")
	{
		std::cout << "It's a tunnel wall\n";
	}
	else if (_command.ToLower() == "west" || _command.ToLower() == "w")
	{
		std::cout << "It's a tunnel wall\n";
	}
	else if (_command.ToLower() == "south" || _command.ToLower() == "s")
	{
		std::cout << "It's a tunnel wall\n";
	}
	else
	{
		std::cout << "Invalid command\n";
		std::cout << "Please re-enter command\n";
	}

}

const int Stage1::CheckKeys()
{
	return _keys;
}

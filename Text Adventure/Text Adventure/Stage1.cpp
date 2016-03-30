

#include "Stage1.h"

int Stage1::_keys = 0;

Stage1::Stage1() : Map()
{
}


Stage1::~Stage1()
{
}

void Stage1::Run(int & currentMap, Player& player)
{
	if (CheckKeys() < 1)
	{
		RequestCommand(); // Ask user for movement input

		if (_command.ToLower() == "north" || _command.ToLower() == "n")
		{
			std::cout << "You walk north until you enter a dimly lit cavern with 3 doors\n";
			std::cout << "One to the East, one to the North and one to the south\n";
			while (currentMap == GetID()) // GetID returns the unique Map ID of map
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
					currentMap = _mapName::RIDDLE; // To RiddleRoom
				}
				else if (_command.ToLower() == "west" || _command.ToLower() == "w")
				{
					std::cout << "The door is locked looks like you need a key to open it\n";
				}
				else if (_command.ToLower() == "south" || _command.ToLower() == "s")
				{
					std::cout << "You just came from that direction\n";
					std::cout << player.GetName() << ": I don't think theres anything there.\n";
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
	else
	{
		std::cout << "You are back in the main room with the 3 doors\n";
		RequestCommand();
		if (_command.ToLower() == "north" || _command.ToLower() == "n")
		{
			if (CheckKeys() < 2)
			{
				std::cout << "The door is locked. Looks like it requires two keys to open.\n";
			}
			else
			{
				std::cout << "You used the key to unlock the door\n";
				currentMap = _mapName::STAGE2;
			}
		}
		else if (_command.ToLower() == "east" || _command.ToLower() == "e")
		{
			std::cout << "You open the door to the East and enter.\n";
			currentMap = _mapName::RIDDLE; // To RiddleRoom
		}
		else if (_command.ToLower() == "west" || _command.ToLower() == "w")
		{
			std::cout << "You use the Stone Key to unlock the door\n";
			currentMap = _mapName::MATH; // To MathRoom
		}
		else if (_command.ToLower() == "south" || _command.ToLower() == "s")
		{
			std::cout << "You just came from that direction\n";
			std::cout << player.GetName() << ": I don't think theres anything there.\n";
		}
		else
		{
			std::cout << "Invalid command\n";
			std::cout << "Please re-enter command\n";
		}
	}
}

void Stage1::ObtainKey()
{
	_keys++;
}

int Stage1::CheckKeys()
{
	return _keys;
}

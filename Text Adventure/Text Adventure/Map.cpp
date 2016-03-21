#include <iostream>
#include "Map.h"

int Map::_G_ID = 0;

Map::Map()
{
	_ID == ++_G_ID;
}


Map::~Map()
{
}

void Map::Input()
{
	_command.SetString();
}

void Map::Update(int& currentLocation)
{
	MyString command = _command.ToLower();

	if (currentLocation == 0)
	{
		if (command.Strcmp("north") == 0 || command.Strcmp("n") == 0)
		{
			std::cout << "You walk north until you enter a";
		}
		else if (command.Strcmp("east") == 0 || command.Strcmp("e") == 0)
		{

		}
		else if (command.Strcmp("south") == 0 || command.Strcmp("s") == 0)
		{

		}
		else if (command.Strcmp("west") == 0 || command.Strcmp("w") == 0)
		{

		}
		else
		{
			std::cout << "Invalid command\n";
			std::cout << "Please re-enter command\n";
		}
	}
}

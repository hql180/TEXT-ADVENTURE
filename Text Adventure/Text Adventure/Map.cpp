#include <iostream>
#include "Map.h"

int Map::_G_ID = 0;

Map::Map()
{
	_ID = _G_ID++;
}


Map::~Map()
{
}

void Map::Run(int & currentMap, Player & player)
{
}



int Map::GetID()
{
	return _ID;
}

void Map::RequestCommand()
{
	std::cout << "Please input command (North, East, West, South, N, E, W, S)\n";
	std::cin >> _command;
}


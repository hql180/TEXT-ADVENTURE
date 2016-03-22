#include <iostream>
#include <vector>
#include <time.h>

#include "MyString.h"
#include "Player.h"
#include "Map.h"
#include "Stage1.h"
#include "RiddleRoom.h"
#include "QuestionPool.h"

int main()
{
	srand(NULL);	
	
	// You wake up in a cold empty tunnel. \n You can see dim moonlight shining in from the hole above you. It appears as though you fell in from above and passed out. (player:no shit...)
	// ...The only path forward is ahead of you.

	// user input forward

	// You walk forward through the tunnel until you enter a large carvern with what appears to be 3 doors

	// user input

	QuestionPool test;
	test.Print();

	system("pause");

	std::vector<Map*> map;

	map.push_back(new Stage1());
	map.push_back(new RiddleRoom());

	Player player;

	std::cout << "You wake up in a cold empty tunnel. \nYou can see dim moonlight shining in from the hole above you. \nIt appears as though you fell in from above and passed out. (" << player.GetName() << ":no shit...)\n";
	std::cout << "...The only path forward is ahead of you.\n";

	int currentMap = 0;

	while (true)
	{
		map[currentMap]->Run(currentMap);
	}
	

	
	
	/*while (currentMap == 0)
	{
		std::cout << "Please input command (North, East, West, South, N, E, W, S)\n";
		player.InputCommand();

		if (player.GetCommand() == "north" || player.GetCommand() == "n")
		{
			std::cout << "You walk north until you enter a dimly lit cavern with 3 doors\n";
			std::cout << "One to the East, one to the North and one to the south\n";
			currentMap = 1;
		}
		else if (player.GetCommand() == "east" || player.GetCommand() == "e")
		{
			std::cout << "It's a tunnel wall\n";
		}
		else if (player.GetCommand() == "west" || player.GetCommand() == "w")
		{
			std::cout << "It's a tunnel wall\n";
		}
		else if (player.GetCommand() == "south" || player.GetCommand() == "s")
		{
			std::cout << "It's a tunnel wall\n";
		}
		else
		{
			std::cout << "Invalid command\n";
			std::cout << "Please re-enter command\n";
		}
	}*/
	int keys = 0;
	while (currentMap == 1)
	{
		
		std::cout << "Please input command (North, East, West, South, N, E, W, S)\n";
		player.InputCommand();

		if (player.GetCommand() == "north" || player.GetCommand() == "n")
		{
			if (keys < 2)
			{
				std::cout << "The door is locked. Looks like it requires two keys to open.\n";
			}
			else
			{
				std::cout << "You used the key to unlock the door\n";
				currentMap = 2;
			}
		}
		else if (player.GetCommand() == "east" || player.GetCommand() == "e")
		{
			std::cout << "You open the door to the East and enter a room with some ancient looking text written on it\n";
			std::cout << "It reads'" << "insert here" << "'\n";
			currentMap = 3;
		}
		else if (player.GetCommand() == "west" || player.GetCommand() == "w")
		{
			std::cout << "It's a tunnel wall\n";
		}
		else if (player.GetCommand() == "south" || player.GetCommand() == "s")
		{
			std::cout << "It's a tunnel wall\n";
		}
		else
		{
			std::cout << "Invalid command\n";
			std::cout << "Please re-enter command\n";
		}
	}


	
	


	system("pause");
	return 0;
}
#include "RiddleRoom.h"


RiddleRoom::RiddleRoom()
{
}


RiddleRoom::~RiddleRoom()
{
}

void RiddleRoom::Run(int & currentMap) // Came from stage1
{
	std::cout << "Upon entering the room you see a wall with some ancient looking text written on it\n"; 
	std::cout << "It reads'" << "insert here" << "'\n";
	std::cout << "Please input command (North, East, West, South, N, E, W, S)\n";
	std::cin >> _command;
	std::cout << "still in riddle room\n";
	int keys = 0;
	
}


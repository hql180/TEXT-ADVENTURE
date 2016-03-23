#include "RiddleRoom.h"


RiddleRoom::RiddleRoom()
{
}


RiddleRoom::~RiddleRoom()
{
}

void RiddleRoom::Run(int & currentMap) // Came from stage1
{
	if (CheckKeys() < 1)
	{
		std::cout << "Upon entering the room you see a wall with some ancient mystical text written on it\n";
		std::cout << "It reads '" << riddle.GetQuestion() << "'\n";
	}
	else
	{
		std::cout << "This is the room where you got the stone key from\n";
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
	while (riddle.CheckSolved())
	{
		std::cout << "Having seen that you have comprehended the profundity of its ancient enigmatic puzzle\n";
		std::cout << "The mysterious spirits of this riddle room causes a stone key to be birthed from the wall\n";
		std::cin >> _command;
		if (_command.ToLower() == "get key" || _command.ToLower() == "take key" || _command.ToLower() == "pick up key")
		{
			ObtainKey();
		}

	}
	
}


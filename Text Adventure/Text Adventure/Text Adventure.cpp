#include <iostream>
#include <vector>
#include <time.h>

#include "MyString.h"
#include "Player.h"
#include "Map.h"
#include "Stage1.h"
#include "RiddleRoom.h"
#include "QuestionPool.h"
#include "MathRoom.h"
#include "Stage2.h"

int main()
{
	srand(NULL);	
	
	/*MyString test;

	test = "02497";

	test.ToLower();

	std::cout << strlen(test.GetString());

	test.PrintString();

	std::cout << rand() % 11;
*/
	system("pause");

	std::vector<Map*> map;

	map.push_back(new Stage1());
	map.push_back(new RiddleRoom());
	map.push_back(new MathRoom());
	map.push_back(new Stage2());

	Player player;

	std::cout << "You wake up in a cold empty tunnel. \nYou can see dim moonlight shining in from the hole above you. \nIt appears as though you fell in from above and passed out. (" << player.GetName() << ":no shit...)\n";
	std::cout << "...The only path forward is ahead of you.\n";

	int currentMap = 0;

	while (true)
	{
		map[currentMap]->Run(currentMap, player);
		//currentMap = map[currentMap]->UpdateMap();
	}
	

	system("pause");
	return 0;
}
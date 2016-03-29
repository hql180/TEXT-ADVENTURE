#pragma once

#include <iostream>
#include <cstdlib>

#include "MyString.h"
#include "QuestionPool.h"
#include "Player.h"


class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Run(int& currentMap, Player& player);

	int GetID();

	void RequestCommand();

protected:
	MyString _name;
	MyString _command;
	static int _G_ID;
	int _ID;
	
	enum _mapName
	{
		STAGE1,
		RIDDLE,
		MATH,
		STAGE2
	};
};


#pragma once
#include "Map.h"
#include "Player.h"

class Stage1 :
	public Map
{
public:
	Stage1();
	virtual ~Stage1();

protected:
	virtual void Run(int& currentMap);

	const int CheckKeys();

private:
	int _keys = 0;
};


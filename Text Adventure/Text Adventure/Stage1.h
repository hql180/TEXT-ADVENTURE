#pragma once
#include "Map.h"


class Stage1 :
	public Map
{
public:
	Stage1();
	virtual ~Stage1();

protected:
	virtual void Run(int& currentMap, Player& player);

	virtual void ObtainKey();

	int CheckKeys();

private:
	static int _keys;
};


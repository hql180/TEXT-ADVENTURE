#pragma once
#include "Map.h"
class Stage2 : public Map
{
public:
	Stage2();
	virtual ~Stage2();
	virtual void Run(int& currentMap, Player& player);

protected:

private:
	bool _intro = false;
};


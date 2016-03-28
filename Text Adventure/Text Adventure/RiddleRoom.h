#pragma once
#include "Stage1.h"
class RiddleRoom : public Stage1
{
public:
	RiddleRoom();
	virtual ~RiddleRoom();

	virtual void Run(int& currentMap, Player& player);

	virtual void ObtainKey();

	

private:
	bool _gotKey = false;
	QuestionPool riddle;
};


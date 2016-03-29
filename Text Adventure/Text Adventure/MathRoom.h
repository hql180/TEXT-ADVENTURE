#pragma once
#include "Stage1.h"
class MathRoom : public Stage1
{
public:
	MathRoom();
	virtual ~MathRoom();

	virtual void Run(int& currentMap, Player& player);

	virtual void ObtainKey();



private:
	bool _gotKey = false;
	bool _solved = false;
	QuestionPool _mathQuestion = 1;

};


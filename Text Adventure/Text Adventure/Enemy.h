#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	Enemy();
	virtual ~Enemy();
protected:
	void AddModifier();
};


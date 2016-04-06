#include "Rat.h"



Rat::Rat() : Enemy()
{
	_name = "Rat";
	_health *= .5f;
	_damage *= .5f;
	_armour = 0;
	_exp = 5;
	_evasion = 1;
}


Rat::~Rat()
{
}



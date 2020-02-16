#pragma once
#ifndef __FLAMETHROWER__
#define __FLAMETHROWER__
#include "Weapon.h"
class Flamethrower : public Weapon
{
public:
	Flamethrower();
	~Flamethrower();
	void Fire() override;
};
#endif
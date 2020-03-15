#pragma once
#ifndef __FLAMETHROWER__
#define __FLAMETHROWER__
#include "Weapon.h"
#include "FlameThrowerWeapon.h"
class Flamethrower : public Weapon
{
public:
	Flamethrower();
	~Flamethrower();
	FlameThrowerWeapon* flameThrower;
	void Fire();

	
};
#endif
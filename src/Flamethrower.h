#pragma once
#ifndef __FLAMETHROWER__
#define __FLAMETHROWER__
#include "Weapon.h"
#include "FlameThrowerWeapon.h"
#include "PlayerShip.h"
class Flamethrower : public Weapon
{
public:
	friend class PlayerShip;
	Flamethrower();
	~Flamethrower();
	FlameThrowerWeapon* flamethrower;
	void Fire();
	glm::vec2 Position();

		
};
#endif
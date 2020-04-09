#pragma once
#ifndef __FLAME_THROWER_WEAPON__
#define __FLAME_THROWER_WEAPON__

#include "PlayerWeapon.h"

class FlameThrowerWeapon :public PlayerWeapon
{
public:
	friend class Flamethrower;
	FlameThrowerWeapon(glm::vec2 position);
	~FlameThrowerWeapon();
	Flamethrower* flamethrower;
	void update() override;
	
	
};

#endif // defined (__FLAME_THROWER_WEAPON__) //

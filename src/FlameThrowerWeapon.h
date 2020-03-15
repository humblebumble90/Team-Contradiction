#pragma once
#ifndef __FLAME_THROWER_WEAPON__
#define __FLAME_THROWER_WEAPON__

#include "PlayerWeapon.h"

class FlameThrowerWeapon :public PlayerWeapon
{
public:
	FlameThrowerWeapon(glm::vec2 position);
	~FlameThrowerWeapon();
	void update() override;
private:
};

#endif // defined (__FLAME_THROWER_WEAPON__) //

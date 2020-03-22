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
	void update() override;
private:
	Flamethrower* m_pflamethrower;
};

#endif // defined (__FLAME_THROWER_WEAPON__) //

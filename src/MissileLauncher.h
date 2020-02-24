#pragma once
#ifndef __MISSILELAUNCHER__
#define __MISSILELAUNCHER__
#include "Weapon.h"
#include "WeaponMissile.h"

//This class instantiates a chosen a weapon type and draws it on the screen
class MissileLauncher :public Weapon
{
public:
	MissileLauncher();
	~MissileLauncher();


	void Fire();

private:
	WeaponMissile* m_pWeaponMissile;
};


#endif // !__MISSILELAUNCHER__


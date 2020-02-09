#pragma once
#pragma once
#ifndef __MISSILELAUNCHER__
#define __MISSILELAUNCHER__

#include "TextureManager.h"
#include "Weapon.h"

//This class instantiates a chosen a weapon type and draws it on the screen
class MissileLauncher :public Weapon
{
public:
	MissileLauncher();
	~MissileLauncher();


	void Fire() override;

private:
	WeaponMissile* m_pWeaponMissile;
};


#endif // !__MISSILELAUNCHER__


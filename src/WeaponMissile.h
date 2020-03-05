#pragma once
#ifndef __WEAPONMISSILE__
#define __WEAPONMISSILE__
#include "PlayerWeapon.h"

//This is the actual missile that gets created by the MissileLauncher class
class WeaponMissile :public PlayerWeapon
{
public:
    WeaponMissile(glm::vec2 position, glm::vec2 velocity);
    ~WeaponMissile();
};

#endif /* defined(__MISSILE__) */


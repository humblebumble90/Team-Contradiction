#pragma once
#ifndef __WEAPONMISSILE__
#define __WEAPONMISSILE__

#include "Weapon.h"
#include "TextureManager.h"
#include "SoundManager.h"

//This is the actual missile that gets created by the MissileLauncher class
class WeaponMissile :public DisplayObject
{
public:
    WeaponMissile();
    ~WeaponMissile();

    void draw() override;
    void update() override;
    void clean() override;

    void Move();

    //getters and setters for weapon speed
    float GetSpeed();
    void SetSpeed(float speed);

private:
    // speed in which the weapon will travel.
    float m_velocity;



};

#endif /* defined(__MISSILE__) */


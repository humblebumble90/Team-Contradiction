#pragma once
#include "DisplayObject.h"
#include "PlayerWeaponTypes.h"
#ifndef __POWER_UP__
#define __POWER_UP__
class Power_Up : public DisplayObject
{
public:
	Power_Up(PlayerWeaponType weaponType);
	~Power_Up();
	
	void draw() override;
	void update() override;
	void clean() override;
	bool getCollided();
	void setCollided(bool newState);
	PlayerWeaponType getWeaponType();
private:
	bool collided;
	void move();
	PlayerWeaponType weapon;
};
#endif /*Defined (__POWER_UP__)*/
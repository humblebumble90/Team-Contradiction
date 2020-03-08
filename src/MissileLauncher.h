#pragma once
#ifndef __MISSILELAUNCHER__
#define __MISSILELAUNCHER__
#include "Weapon.h"

//This class instantiates a chosen a weapon type and draws it on the screen
class MissileLauncher :public Weapon
{
public:
	MissileLauncher();
	~MissileLauncher();


	void Fire();
	void Fire(glm::vec2 trajectory);
};


#endif // !__MISSILELAUNCHER__


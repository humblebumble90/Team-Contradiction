#pragma once
#ifndef __CANNONBALL__
#define __CANNONBALL__

#include "PlayerWeapon.h"
class Cannonball :public PlayerWeapon
{
public:
	Cannonball(glm::vec2 position, glm::vec2 velocity);
	~Cannonball();
private:

};
#endif // defined(__CANNONBALL__) //

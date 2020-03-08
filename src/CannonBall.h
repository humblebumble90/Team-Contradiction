#pragma once
#ifndef __CANNONBALL__
#define __CANNONBALL__

#include "PlayerWeapon.h"
class CannonBall :public PlayerWeapon
{
public:
	CannonBall(glm::vec2 position, glm::vec2 velocity);
	~CannonBall();
private:

};
#endif // defined(__CANNONBALL__) //



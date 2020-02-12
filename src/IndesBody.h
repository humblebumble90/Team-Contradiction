#pragma once
#ifndef __INDESBODY__
#define __INDESBODY__
#include "ShipComponent.h"
class IndesBody : public ShipComponent
{
public:
	IndesBody(bool projectile);
	~IndesBody();
	void Damage(ShipComponent collision); //Subject for removal. At this point, it exists only for use with sounds and animations
private:
	bool isProjectile;
};
#endif
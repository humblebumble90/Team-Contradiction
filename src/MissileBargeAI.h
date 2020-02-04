#pragma once
#ifndef __MISSILEBARGE__
#define __MISSILEBARGE__
#include "FlyOntoScreenAI.h"
class MissileBargeAI : FlyOntoScreenAI
{
public:
	MissileBargeAI(glm::vec2 transform);
	~MissileBargeAI();
	void SecondaryFunction() override;
private:
	float topLimit, bottomLimit; //Set all these numbers later
	int attackCooldown = 75, attackCooldownReset = 75;
};
#endif
#pragma once
#ifndef __CANNONBARGE__
#define __CANNONBARGE__
#include "FlyOntoScreenAI.h"
class CannonBargeAI : public FlyOntoScreenAI
{
public:
	CannonBargeAI(glm::vec2 transform);
	~CannonBargeAI();
	void SecondaryFunction() override;
private:
	int rotation = 0, attackCooldown = 50, attackCooldownReset = 50;
};
#endif
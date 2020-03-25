#pragma once
#ifndef __RAIN__
#define __RAIN__
#include "FlyOntoScreenAI.h"

class RainAI : public FlyOntoScreenAI
{
public:
	RainAI(glm::vec2 transform);
	~RainAI();
	void SecondaryFunction() override;
private:
	int firingCooldown = 0, firingCooldownReset = 90, rainFiringCooldownReset = 60, firingIteration = 0, rainIteration = 5, rainCooldown = 800, rainCooldownReset = 600;
	glm::vec2 targetLoc;
	void getNewTarget();
	float baseSpeed = 5.00f;
};

#endif
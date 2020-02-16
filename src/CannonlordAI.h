#pragma once
#ifndef __CANNONLORD__
#define __CANNONLORD__
#include "FlyOntoScreenAI.h"

class CannonlordAI : public FlyOntoScreenAI
{
public:
	CannonlordAI(glm::vec2 transform);
	~CannonlordAI();
	void SecondaryFunction() override;
private:
	float baseSpeed=0.075f; //Subject to testing
	int rotation = 0, rotationTimer = 0, rotationTimerReset = 30, rotationFactor = 3, rotationIteration = 0, movementTimer, movementTimerReset, attackCooldown = 25, attackCooldownReset = 25;
	std::vector<int> rotationValues = { 0, -90, -90, -90, 0, 90, 90, 90 };
};

#endif
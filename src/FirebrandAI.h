#pragma once
#ifndef __FIREBRAND__
#define __FIREBRAND__
#include "FlyOntoScreenAI.h"
class FirebrandAI : public FlyOntoScreenAI
{
public:
	FirebrandAI(glm::vec2 transform);
	~FirebrandAI();
	void SecondaryFunction() override;
private:
	bool hasTarget = true;
	int ramCounter = 3, ramCounterReset = 3, ramCooldown = 0, ramCooldownReset = 50/*Subject to tesing*/, missileCooldown = 25, missileCooldownReset = 25;
	int cannonCooldown = 100, cannonCooldownReset = 100;
	float moveTarget, baseSpeed = 0.075f;
};
#endif
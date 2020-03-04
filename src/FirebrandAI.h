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
	bool hasTarget = false;
	int ramCounter = 3, ramCounterReset = 3, ramCooldown = 0, ramCooldownReset = 55/*Subject to tesing*/, missileCooldown = 30, missileCooldownReset = 30;
	int cannonCooldown = 60, cannonCooldownReset = 60;
	float moveTarget, baseSpeed = 5.00f;
};
#endif
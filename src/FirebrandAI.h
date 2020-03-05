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
<<<<<<< HEAD
	int ramCounter = 3, ramCounterReset = 3, ramCooldown = 0, ramCooldownReset = 50/*Subject to tesing*/, missileCooldown = 25, missileCooldownReset = 25;
=======
	int ramCounter = 3, ramCounterReset = 3, ramCooldown = 0, ramCooldownReset = 100/*Subject to tesing*/, missileCooldown = 25, missileCooldownReset = 25;
>>>>>>> parent of fb161a7... Completely Debugged Firebrand:
	int cannonCooldown = 100, cannonCooldownReset = 100;
	float moveTarget, baseSpeed = 10.00f;
};
#endif
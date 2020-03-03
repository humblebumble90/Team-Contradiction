#pragma once
#ifndef __GUARDIAN__
#define __GUARDIAN__
#include "AI.h"
class GuardianAI : public AI
{
public:
	GuardianAI(glm::vec2 transform);
	~GuardianAI();
	void PrimaryFunction() override;
private:
	int firingCooldown = 50, firingCooldownReset = 50;
};
#endif
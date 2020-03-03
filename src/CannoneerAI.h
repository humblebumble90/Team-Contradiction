#pragma once
#ifndef __CANNONEER__
#define __CANNONEER__
#include "AI.h"
class CannoneerAI : public AI
{
public:
	CannoneerAI(glm::vec2 transform);
	~CannoneerAI();
	void PrimaryFunction() override;
private:
	int firingCooldown = 50, firingCooldownReset = 50;
};
#endif

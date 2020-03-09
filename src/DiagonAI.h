#pragma once
#ifndef __DIAGON__
#define __DIAGON__
#include "PlayerLockAI.h"
class DiagonAI : public PlayerLockAI
{
public:
	DiagonAI(glm::vec2 transform);
	~DiagonAI();
	void PrimaryFunction() override;
private:
	int firingCooldown = 50, firingCooldownReset = 50;
};
#endif

#pragma once
#ifndef __DEATHCAGE__
#define __DEATHCAGE__
#include "FlyOntoScreenAI.h"
class DeathcageAI : FlyOntoScreenAI
{
public:
	DeathcageAI(glm::vec2 transform);
	~DeathcageAI();
	void SecondaryFunction() override;
private:
	std::vector<Cannon> topCannons, bottomCannons, centerCannons;
	int cannonIteration = 0, cannonMaximum = 8, centerIteration = 0, centerMaximum = 9, attackCooldown = 25, attackCooldownReset = 25;
};
#endif
#pragma once
#ifndef __DEATHCAGE__
#define __DEATHCAGE__
#include "FlyOntoScreenAI.h"
#include "Weapon.h"
class DeathcageAI : public FlyOntoScreenAI
{
public:
	DeathcageAI(glm::vec2 transform);
	~DeathcageAI();
	void SecondaryFunction() override;
private:
	std::vector<Weapon> topCannons, bottomCannons, centerCannons;
	int cannonIteration = 0, cannonMaximum = 8, centerIteration = 0, centerMaximum = 9, attackCooldown = 25, attackCooldownReset = 25;
};
#endif
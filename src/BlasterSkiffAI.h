#pragma once
#ifndef __BLASTERSKIFF__
#define __BLASTERSKIFF__
#include "FlyOntoScreenAI.h"

class BlasterSkiffAI : public FlyOntoScreenAI
{
public:
	BlasterSkiffAI(glm::vec2 transform);
	~BlasterSkiffAI();
	void SecondaryFunction() override;
private:
	float topBouncePoint, bottomBouncePoint, spawnPoint; //set these numbers via testing
	int firingCooldown = 30, firingCooldownReset = 30, firingIteration = 0;
};

#endif
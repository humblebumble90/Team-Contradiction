#pragma once
#ifndef __BLASTERSKIFF__
#define __BLASTERSKIFF__
#include "FlyOntoScreenAI.h"

class BlasterSkiffAI : FlyOntoScreenAI
{
public:
	BlasterSkiffAI(glm::vec2 transform);
	~BlasterSkiffAI();
	void SecondaryFunction() override;
private:
	float topBouncePoint, bottomBouncePoint; //set these numbers via testing
	int firingCooldown = 10, firingCooldownReset = 10, firingIteration = 0;
};

#endif
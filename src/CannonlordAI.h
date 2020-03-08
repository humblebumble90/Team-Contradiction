#pragma once
#ifndef __CANNONLORD__
#define __CANNONLORD__
#include "FlyOntoScreenAI.h"
#include "Config.h"

class CannonlordAI : public FlyOntoScreenAI
{
public:
	CannonlordAI(glm::vec2 transform);
	~CannonlordAI();
	void SecondaryFunction() override;
	double getRotation();
private:
	float baseSpeed = 10.00f; //Subject to testing
	int positiveRotation = 0, rotation = 0, rotationTimer = 0, rotationTimerReset = 30, rotationFactor = 3, rotationIteration = 0, movementTimer = Config::SCREEN_WIDTH / 20, movementTimerResetX = Config::SCREEN_WIDTH / 20, movementTimerResetY = Config::SCREEN_HEIGHT / 20, attackCooldown = 25, attackCooldownReset = 25;
	std::vector<int> rotationValues = { 0, -90, -90, -90, 0, 90, 90, 90 };
};

#endif
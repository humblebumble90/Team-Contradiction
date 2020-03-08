#pragma once
#ifndef __CANNONLORD__
#define __CANNONLORD__
#include "FlyOntoScreenAI.h"
#include "Config.h"
#include "Cannon.h"

class CannonlordAI : public FlyOntoScreenAI
{
public:
	CannonlordAI(glm::vec2 transform);
	~CannonlordAI();
	void SecondaryFunction() override;
	double getRotation();
private:
	float baseSpeed = 5.00f; //Subject to testing
	int localRotation = 0, positiveRotation = 0, rotation = 0, rotationTimer = 0, rotationTimerReset = 30, rotationFactor = 3, rotationIteration = 0, movementTimer = Config::SCREEN_WIDTH / 10, movementTimerResetX = Config::SCREEN_WIDTH / 10, movementTimerResetY = Config::SCREEN_HEIGHT / 10, attackCooldown = 45, attackCooldownReset = 45;
	std::vector<int> rotationValues = { 0, -90, -90, -90, 0, 90, 90, 90 };
	std::vector<Cannon> topCannons, leftCannons, bottomCannons, rightCannons;
	void cannonlordFire(Vector2 up, Vector2 down, Vector2 left, Vector2 right);
};

#endif
#pragma once
#ifndef __PLAYERLOCK__
#define __PLAYERLOCK__
#include "AI.h"
class PlayerLockAI : public AI
{
public:
	PlayerLockAI();
	PlayerLockAI(Enemy* enemyParent, float bSpeed, glm::vec2 targetTransform);
	~PlayerLockAI();
	void Initialize(Enemy* enemyParent, float bSpeed, glm::vec2 targetTransform);
private:
	float baseSpeed;
	void setup(Enemy* enemyParent, float bSpeed, glm::vec2 targetTransform);
};
#endif
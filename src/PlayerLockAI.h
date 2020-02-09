#pragma once
#ifndef __PLAYERLOCK__
#define __PLAYERLOCK__
#include "AI.h"
class PlayerLockAI : public AI
{
public:
	PlayerLockAI();
	PlayerLockAI(Enemy enemyParent, float bSpeed);
	~PlayerLockAI();
private:
	float baseSpeed;
};
#endif
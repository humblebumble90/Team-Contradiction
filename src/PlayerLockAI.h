#pragma once
#ifndef __PLAYERLOCK__
#define __PLAYERLOCK__
#include "AI.h"
class PlayerLockAI : public AI
{
public:
	PlayerLockAI();
	~PlayerLockAI();
	void Initialize();
	void Initialize(glm::vec2 target);
protected:
	float baseSpeed;
	void setSpeed(glm::vec2 target);
};
#endif
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
protected:
	float baseSpeed;
};
#endif
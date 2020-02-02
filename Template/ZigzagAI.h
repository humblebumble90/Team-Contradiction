#pragma once
#ifndef __ZIGZAG__
#define __ZIGZAG__
#endif
#include "AI.h"
class ZigzagAI : public AI
{
public:
	ZigzagAI(float transform[2]);
	~ZigzagAI();
	void PrimaryFunction() override;
private:
	int bounceTimer = 50, bounceTimerReset = 50; //Reset subject to change
};
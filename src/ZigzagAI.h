#pragma once
#ifndef __ZIGZAG__
#define __ZIGZAG__
#include "AI.h"
class ZigzagAI : public AI
{
public:
	ZigzagAI(glm::vec2 transform);
	~ZigzagAI();
	void PrimaryFunction() override;
private:
	int bounceTimer = 50, bounceTimerReset = 50; //Reset subject to change
};
#endif
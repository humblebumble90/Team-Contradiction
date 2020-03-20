#pragma once
#ifndef __CHAOS__
#define __CHAOS__
#include "FlyOntoScreenAI.h"

class ChaosAI : public FlyOntoScreenAI {
public:
	ChaosAI(glm::vec2 transform);
	~ChaosAI();
	void SecondaryFunction() override;
private:
	float baseSpeed = 5.00f;
	int timer = 60, timerReset = 60, phase1 = 75, phase2 = 40, phase = 0, reverseTimer = 0, reverseTimerReset = 600;
	bool canFire = true;
};
#endif

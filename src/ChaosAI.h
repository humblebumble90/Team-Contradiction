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
};
#endif

#pragma once
#ifndef __FIREBARGE__
#define __FIREBARGE__
#include "FlyOntoScreenAI.h"
class FireBargeAI : public FlyOntoScreenAI
{
public:
	FireBargeAI(glm::vec2 transform);
	~FireBargeAI();
	void SecondaryFunction() override;
private:
	float baseSpeed = 10.00f, topLimit, leftLimit, bottomLimit, rightLimit;
};
#endif
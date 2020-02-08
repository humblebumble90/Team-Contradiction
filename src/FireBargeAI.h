#pragma once
#ifndef __FIREBARGE__
#define __FIREBARGE__
#include "FlyOntoScreenAI.h"
class FireBargeAI : FlyOntoScreenAI
{
public:
	FireBargeAI(glm::vec2 transform);
	~FireBargeAI();
	void SecondaryFunction() override;
private:
	float baseSpeed = 0.1, topLimit, leftLimit, bottomLimit, rightLimit; //Set all these numbers later
};
#endif
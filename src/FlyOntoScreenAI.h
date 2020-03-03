#pragma once
#ifndef __FLYONTOSCREEN__
#define __FLYONTOSCREEN__
#include "AI.h"
class FlyOntoScreenAI : public AI
{
public:
	FlyOntoScreenAI();
	virtual ~FlyOntoScreenAI(); //May need to change to not be virtual
	void PrimaryFunction() override;
	virtual void SecondaryFunction();
	glm::vec2 GetSpeed() override;
protected:
	glm::vec2 target;
	glm::vec2 entrySpeed = glm::vec2 (-5, 0);
private:
	bool atTarget = false;
};

#endif
#pragma once
#ifndef __BLAST__
#define __BLAST__
#include "AI.h"
class BlastAI : public AI
{
public:
	BlastAI(glm::vec2 transform);
	~BlastAI();
	void PrimaryFunction() override;
private:
	int firingCooldown = 75, firingCooldownReset = 75;
};
#endif
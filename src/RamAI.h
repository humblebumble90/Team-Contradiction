#pragma once
#ifndef __RAM__
#define __RAM__
#endif
#include "PlayerLockAI.h"
class RamAI : public PlayerLockAI
{
public:
	RamAI(glm::vec2 transform);
	~RamAI();
};
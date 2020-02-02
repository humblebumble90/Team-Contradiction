#pragma once
#ifndef __RAM__
#define __RAM__
#endif
#include "PlayerLockAI.h"
class RamAI : public PlayerLockAI
{
public:
	RamAI(float transform[2]);
	~RamAI();
};
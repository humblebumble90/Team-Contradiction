#pragma once
#ifndef __ENEMYMISSILE__
#define __ENEMYMISSILE__
#endif
#include "PlayerLockAI.h"
class EnemyMissileAI : public PlayerLockAI
{
public:
	EnemyMissileAI(float transform[2]);
	~EnemyMissileAI();
};
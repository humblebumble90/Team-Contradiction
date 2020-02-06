#pragma once
#ifndef __ENEMYMISSILE__
#define __ENEMYMISSILE__
#endif
#include "PlayerLockAI.h"
class EnemyMissileAI : public PlayerLockAI
{
public:
	EnemyMissileAI(glm::vec2 transform);
	~EnemyMissileAI();
};
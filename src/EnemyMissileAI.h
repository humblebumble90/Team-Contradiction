#pragma once
#ifndef __ENEMYMISSILE__
#define __ENEMYMISSILE__
#include "PlayerLockAI.h"
class EnemyMissileAI : public PlayerLockAI
{
public:
	EnemyMissileAI(glm::vec2 transform);
	~EnemyMissileAI();
};
#endif
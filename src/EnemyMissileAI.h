#pragma once
#ifndef __ENEMYMISSILE__
#define __ENEMYMISSILE__
#include "PlayerLockAI.h"
class EnemyMissileAI : public PlayerLockAI
{
public:
	EnemyMissileAI(glm::vec2 transform);
	EnemyMissileAI(glm::vec2 transform, glm::vec2 target);
	~EnemyMissileAI();
};
#endif
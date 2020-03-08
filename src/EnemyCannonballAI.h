#pragma once
#ifndef __ENEMYCANNONBALL__
#define __ENEMYCANNONBALL__
#include "PlayerLockAI.h"
class EnemyCannonballAI : public PlayerLockAI {
public:
	EnemyCannonballAI(glm::vec2 transform, glm::vec2 trajectory);
	~EnemyCannonballAI();
};
#endif
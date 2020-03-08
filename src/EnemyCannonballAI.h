#pragma once
#ifndef __ENEMYCANNONBALL__
#define __ENEMYCANNONBALL__
#include "AI.h"
#include "Vector2.h"
class EnemyCannonballAI : public AI {
public:
	EnemyCannonballAI(glm::vec2 transform, glm::vec2 trajectory);
	EnemyCannonballAI(glm::vec2 transform, Vector2 trajectory);
	~EnemyCannonballAI();
};
#endif
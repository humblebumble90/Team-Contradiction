#pragma once
#ifndef __ENEMY_FLAMETHROWER_AI__
#define __ENEMY__FLAMETHROWER_AI__
#include "AI.h"
class EnemyFlamethrowerAI:public AI
{
public:
	EnemyFlamethrowerAI(glm::vec2 transform);
	~EnemyFlamethrowerAI();
};
#endif // !__ENEMY_FLAMETHROWER_AI__


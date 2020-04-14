#pragma once
#ifndef __ENEMY_FLAMETHROWER_AI__
#define __ENEMY__FLAMETHROWER_AI__
#include "AI.h"
#include "Flamethrower.h"
class EnemyFlamethrowerAI:public AI
{
public:
	EnemyFlamethrowerAI(Flamethrower* ft);
	~EnemyFlamethrowerAI();
	void PrimaryFunction() override;
	int getRotation();
private:
	AI* attachedWeapon;
	int id;
	int rotation = 0;
	glm::vec2 transform;
};
#endif // !__ENEMY_FLAMETHROWER_AI__


#pragma once
#ifndef __ENEMY__
#define __ENEMY__
#include "Frame.h"
//To instantiate an enemy, instantiate that enemy's AI and give it coordinates. The AI's constructor will start a chain reaction that spawns said enemy
class Enemy : public DisplayObject
{
public:
	friend class AI;
	Enemy();
	Enemy(Frame* enemyFrame, int enemyHealth, AI* enemyAI, glm::vec2 targetTransform);
	~Enemy();
	void Damage(int i) override;
	Frame* GetFrame();
#pragma region From GameObject
	void draw() override;
	void update() override;
	void clean() override;
#pragma endregion
private:
	Frame* frame;
	int health;
	AI* aI;
	std::string name;
	void Move();
};
#endif
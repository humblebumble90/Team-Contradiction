#include "Enemy.h"

Enemy::Enemy(){/*DANGER! Do not use!*/ }

Enemy::Enemy(Frame enemyFrame, int enemyHealth, AI* enemyAI, float targetTransform[2])
{
	frame = enemyFrame;
	frame.Initialize(this);
	health = enemyHealth;
	aI = enemyAI;
	transform[0] = targetTransform[0];
	transform[1] = targetTransform[1];
}

Enemy::~Enemy()
{
}

void Enemy::Damage()
{
}

float Enemy::GetTransform(int i)
{
	if (i==1 || i ==0)
		return transform[i];
	return NULL;
}

Frame Enemy::GetFrame()
{
	return frame;
}

void Enemy::Move()
{
	transform[0] += aI->GetSpeed(0);
	transform[1] += aI->GetSpeed(1);
}

void Enemy::draw()
{
}

void Enemy::update()
{
	Move();
	aI->PrimaryFunction();
}

void Enemy::clean()
{
}

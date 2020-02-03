#include "Enemy.h"

Enemy::Enemy(){/*DANGER! Do not use!*/ }

Enemy::Enemy(Frame enemyFrame, int enemyHealth, AI* enemyAI, glm::vec2 targetTransform)
{
	frame = enemyFrame;
	frame.Initialize(this);
	health = enemyHealth;
	aI = enemyAI;
	transform = targetTransform;
}

Enemy::~Enemy()
{
}

void Enemy::Damage(int i)
{
	health -= i;
	if (health <= 0)
	{
		//kill self
	}
}

glm::vec2 Enemy::GetTransform()
{
	return transform;
}

Frame Enemy::GetFrame()
{
	return frame;
}

void Enemy::Move()
{
	transform += aI->GetSpeed;
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

#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(){/*DANGER! Do not use!*/ }

Enemy::Enemy(Frame enemyFrame, int enemyHealth, AI* enemyAI, glm::vec2 targetTransform)
{
	frame = enemyFrame;
	frame.Initialize(this);
	health = enemyHealth;
	aI = enemyAI;
	setPosition(targetTransform);
}

Enemy::~Enemy()
{
}

void Enemy::Damage(int i)
{
	health -= i;
	if (health <= 0)
	{
		TheGame::DestroyEnemy(this);
	}
}

Frame Enemy::GetFrame()
{
	return frame;
}

void Enemy::Move()
{
	setPosition(getPosition() + aI->GetSpeed());
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

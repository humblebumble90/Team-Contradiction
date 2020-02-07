#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(){/*DANGER! Do not use!*/ }

Enemy::Enemy(Frame enemyFrame, int enemyHealth, AI* enemyAI, glm::vec2 targetTransform)
{
	name = typeid(enemyAI).name();
	name = name.substr(0, name.length - 2);
	frame = enemyFrame;
	frame.Initialize(this);
	health = enemyHealth;
	aI = enemyAI;
	setPosition(targetTransform);
	TheTextureManager::Instance()->load("../Assets/textures/"+name+".png",
		name, TheGame::Instance()->getRenderer());
}

Enemy::~Enemy()
{
	TheTextureManager::Instance()->draw("enemy", getPosition().x, getPosition().y, frame.getGridSize()*frame.GridWidth(), frame.getGridSize() * frame.GridHeight(),
		TheGame::Instance()->getRenderer());
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

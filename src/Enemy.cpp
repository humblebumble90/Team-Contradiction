#include "Enemy.h"
#include "Game.h"
#include "AI.h"
#include "Frame.h"
#include "PlayerLockAI.h"

Enemy::Enemy(){/*DANGER! Do not use!*/ }

Enemy::Enemy(Frame* enemyFrame, int enemyHealth, AI* enemyAI, glm::vec2 targetTransform, std::string enemyName):
	frame(enemyFrame), health(enemyHealth), aI(enemyAI)
{
	/*if (name == "EnemyMissile" || name == "Ram") {
		(((PlayerLockAI*)aI)->Initialize(this, 10.00f, targetTransform));
	}*/
	frame->Initialize(this);
	setPosition(targetTransform);
	changeTexture(enemyName);
}

Enemy::~Enemy()
{

}

void Enemy::Damage(int i)
{
	health -= i;
	if (health <= 0)
	{
		TheGame::Instance()->destroyEnemy(this);
	}
}

Frame* Enemy::GetFrame()
{
	return frame;
}

void Enemy::Move()
{
	setPosition(getPosition() + aI->GetSpeed());
	if (getPosition().x + ((GetFrame()->GridWidth() * GetFrame()->getGridSize()) / 2) <= 0) {
		TheGame::Instance()->destroyEnemy(this);
	}
}

void Enemy::draw()
{
	TheTextureManager::Instance()->draw(name, getPosition().x, getPosition().y, frame->getGridSize() * frame->GridWidth(), frame->getGridSize() * frame->GridHeight(),
		TheGame::Instance()->getRenderer());
	//std::cout << name << std::endl;
}

void Enemy::update()
{
	Move();
	aI->PrimaryFunction();
}

void Enemy::clean()
{
}

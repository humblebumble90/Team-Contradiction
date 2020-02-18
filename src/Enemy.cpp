#include "Enemy.h"
#include "Game.h"
#include "AI.h"
#include "Frame.h"

Enemy::Enemy(){/*DANGER! Do not use!*/ }

Enemy::Enemy(Frame* enemyFrame, int enemyHealth, AI* enemyAI, glm::vec2 targetTransform, std::string enemyName):
	frame(enemyFrame), health(enemyHealth), aI(enemyAI), name(enemyName)
{
	frame->Initialize(this);
	setPosition(targetTransform);
	TheTextureManager::Instance()->load("../Assets/textures/"+name+".png",
		name, TheGame::Instance()->getRenderer());
	//std::cout << enemyAI->GetParent() << std::endl;
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
	//std::cout << aI << std::endl;
}

void Enemy::draw()
{
	TheTextureManager::Instance()->draw("enemy", getPosition().x, getPosition().y, frame->getGridSize() * frame->GridWidth(), frame->getGridSize() * frame->GridHeight(),
		TheGame::Instance()->getRenderer());
}

void Enemy::update()
{
	Move();
	aI->PrimaryFunction();
}

void Enemy::clean()
{
}

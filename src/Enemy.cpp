#include "Enemy.h"
#include "Game.h"
#include "AI.h"
#include "Frame.h"
#include "PlayerLockAI.h"
#include "CannonlordAI.h"

Enemy::Enemy(){/*DANGER! Do not use!*/ }

Enemy::Enemy(Frame* enemyFrame, int enemyHealth, AI* enemyAI, glm::vec2 targetTransform, std::string enemyName):
	frame(enemyFrame), health(enemyHealth), aI(enemyAI)
{
	name = enemyName;
	/*if (name == "EnemyMissile" || name == "Ram") {
		(((PlayerLockAI*)aI)->Initialize(this, 10.00f, targetTransform));
	}*/
	frame->Initialize(this);
	setPosition(targetTransform);
	TheTextureManager::Instance()->load("../Assets/textures/"+name+".png",
		name, TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/" + name + "Hit.png",
		name+"Hit", TheGame::Instance()->getRenderer());
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
	else {
		hitTimer = hitTimerReset;
	}
}

Frame* Enemy::GetFrame()
{
	return frame;
}

AI* Enemy::getAI()
{
	return aI;
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
	std::string s = hitTimer > 0 ? name + "Hit" : name;
	if (name == "Cannonlord") {
		TheTextureManager::Instance()->draw(s, getPosition().x - (frame->getGridSize() * frame->GridWidth() / 2), getPosition().y - (frame->getGridSize() * frame->GridHeight() / 2), frame->getGridSize() * frame->GridWidth(), frame->getGridSize() * frame->GridHeight(),
			TheGame::Instance()->getRenderer(), ((CannonlordAI*)aI)->getRotation(), 255, SDL_FLIP_NONE);
	}
	else {
		TheTextureManager::Instance()->draw(s, getPosition().x-(frame->getGridSize()*frame->GridWidth()/2), getPosition().y - (frame->getGridSize() * frame->GridHeight() / 2), frame->getGridSize() * frame->GridWidth(), frame->getGridSize() * frame->GridHeight(),
			TheGame::Instance()->getRenderer());
	}
	//std::cout << name << std::endl;
}

void Enemy::update()
{
	Move();
	aI->PrimaryFunction();
	if (hitTimer > 0) {
		--hitTimer;
	}
}

void Enemy::clean()
{
}

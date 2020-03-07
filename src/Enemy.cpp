#include "Enemy.h"
#include "Game.h"
#include "FlyOntoScreenAI.h"
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
	changeTexture(enemyName);
}

Enemy::~Enemy()
{

}

void Enemy::Damage(int i)
{
	bool doDamage = true;
	if (((FlyOntoScreenAI*)aI)->isBoss){
		if (!((FlyOntoScreenAI*)aI)->isAtTarget()) {
			doDamage = false;
		}
	}
	if (doDamage) {
		health -= i;
		if (health <= 0)
		{
			TheGame::Instance()->destroyEnemy(this);
		}
		else {
			hitTimer = hitTimerReset;
		}
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
	if (health <=1 && (
		(getPosition().x + ((GetFrame()->GridWidth() * GetFrame()->getGridSize()) / 2) <= 0) ||
		(getPosition().x >= Config::SCREEN_WIDTH*1.5) ||
		(getPosition().y + ((GetFrame()->GridHeight() * GetFrame()->getGridSize()) / 2) <= 0) ||
		(getPosition().y - ((GetFrame()->GridHeight() * GetFrame()->getGridSize()) / 2) >= Config::SCREEN_HEIGHT)
		)) {
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

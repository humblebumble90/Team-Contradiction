#include "PlayerLockAI.h"
#include "Game.h"

PlayerLockAI::PlayerLockAI(){/*DANGER! Do not use!*/ }

PlayerLockAI::PlayerLockAI(Enemy* enemyParent, float bSpeed, glm::vec2 targetTransform)
{
	setup(enemyParent, bSpeed, targetTransform);
}

PlayerLockAI::~PlayerLockAI(){}

void PlayerLockAI::Initialize(Enemy* enemyParent, float bSpeed, glm::vec2 targetTransform)
{
	//std::cout << bSpeed<< std::endl;
	setup(enemyParent, bSpeed, targetTransform);
	//std::cout << GetSpeed().x << std::endl;
}

void PlayerLockAI::setup(Enemy* enemyParent, float bSpeed, glm::vec2 targetTransform)
{
	parent = enemyParent;
	baseSpeed = bSpeed;
	//Get target
	float tX = TheGame::Instance()->getPlayerPosition().x;
	float tY = TheGame::Instance()->getPlayerPosition().y;
	float xDif = abs(targetTransform.x - tX), yDif = abs(targetTransform.y - tY);
	bool xIsCloser = xDif > yDif;
	switch (xIsCloser)
	{
	case true:
		speed.x = baseSpeed;
		speed.y = yDif / xDif * baseSpeed;
		break;
	case false:
		speed.y = baseSpeed;
		speed.x = xDif / yDif * baseSpeed;
		break;
	}
	speed.x = targetTransform.x > tX ? -speed.x : speed.x;
	speed.y = targetTransform.y > tY ? -speed.y : speed.y;
	//std::cout << speed.x << std::endl;
}



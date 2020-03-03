#include "PlayerLockAI.h"
#include "Game.h"

PlayerLockAI::PlayerLockAI(){/*DANGER! Do not use!*/ }

PlayerLockAI::~PlayerLockAI(){}

void PlayerLockAI::Initialize()
{
	setSpeed(TheGame::Instance()->getPlayerPosition());
}

void PlayerLockAI::Initialize(glm::vec2 target)
{
	setSpeed(target);
}

void PlayerLockAI::setSpeed(glm::vec2 target)
{
	//Get target
	float tX = target.x;
	float tY = target.y;
	float xDif = abs(GetParent()->getPosition().x - tX), yDif = abs(GetParent()->getPosition().y - tY);
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
	speed.x = GetParent()->getPosition().x > tX ? -speed.x : speed.x;
	speed.y = GetParent()->getPosition().y > tY ? -speed.y : speed.y;
	//std::cout << speed.x << std::endl;
}



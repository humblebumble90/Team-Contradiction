#include "PlayerLockAI.h"
#include "Game.h"

PlayerLockAI::PlayerLockAI(){/*DANGER! Do not use!*/ }

PlayerLockAI::PlayerLockAI(Enemy enemyParent, float bSpeed)
{
	parent = enemyParent;
	baseSpeed = bSpeed;

	//Get target
	float tX = TheGame.Instance().GetCurrentScene().GetPlayerLocation().x;
	float tY = TheGame.Instance().GetCurrentScene().GetPlayerLocation().y;
	float xDif = abs(parent.getPosition().x - tX), yDif = abs(parent.getPosition().y - tY);
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
	speed.x = parent.getPosition().x > tX ? -speed.x : speed.x;
	speed.y = parent.getPosition().y > tY ? -speed.y : speed.y;
}

PlayerLockAI::~PlayerLockAI(){}
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
	float xDif = abs(parent.GetTransform(0) - tX), yDif = abs(parent.GetTransform(1) - tY);
	bool xIsCloser = xDif > yDif;
	switch (xIsCloser)
	{
	case true:
		speed[0] = baseSpeed;
		speed[1] = yDif / xDif * baseSpeed;
		break;
	case false:
		speed[1] = baseSpeed;
		speed[0] = xDif / yDif * baseSpeed;
		break;
	}
	speed[0] = parent.GetTransform(0) > tX ? -speed[0] : speed[0];
	speed[1] = parent.GetTransform(1) > tY ? -speed[1] : speed[1];
}

PlayerLockAI::~PlayerLockAI(){}
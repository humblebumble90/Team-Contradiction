#include "CannonlordAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "Cannon.h"

CannonlordAI::CannonlordAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		Blank(), Cannon(), BasicBody(), BasicBody(), Cannon(), BasicBody(), BasicBody(), Cannon(), Blank(),
		Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon(),
		BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon(),
		Blank(), Cannon(), BasicBody(), BasicBody(), Cannon(), BasicBody(), BasicBody(), Cannon(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(40, //Enemy is 360px by 240px
	build, 9, 6), 200, //Will tweak if 50 health proves to be too much or too little
		this, transform, "Cannonlord");
	speed.x = -baseSpeed;
	target = glm::vec2(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT / 2);
}

CannonlordAI::~CannonlordAI()
{
}

void CannonlordAI::SecondaryFunction()
{
	#pragma region Fire Cannons
	--attackCooldown;
	if (attackCooldown <= 0)
	{
		int z = 0;
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			//DANGER! Rotation MAY be backwards (needs testing) [it shouldn't be backwards, but just in case...]
			if (
				(positiveRotation >=0 && positiveRotation < 90 && z < 3) ||
				(positiveRotation >= 90 && positiveRotation < 180 && z % 2 == 1 && z >=3 && z <= 6) ||
				(positiveRotation >= 180 && positiveRotation < 270 && z > 6) ||
				(positiveRotation >= 270 && positiveRotation < 360 && z % 2 == 0 && z >= 3 && z <= 6)
				)//Fire up
			{
				((Cannon*)& w)->Fire(glm::vec2(0 + rotation / 90, -1 + rotation / 90));
			}
			else if (
				(positiveRotation >= 0 && positiveRotation < 90 && z > 6) ||
				(positiveRotation >= 90 && positiveRotation < 180 && z % 2 == 0 && z >= 3 && z <= 6) ||
				(positiveRotation >= 180 && positiveRotation < 270 && z < 3) ||
				(positiveRotation >= 270 && positiveRotation < 360 && z % 2 == 1 && z >= 3 && z <= 6)
				) //Fire down
			{
				((Cannon*)& w)->Fire(glm::vec2(0 - rotation / 90, 1 - rotation / 90));
			}
			else if (
				(positiveRotation >= 0 && positiveRotation < 90 && z % 2 == 1) ||
				(positiveRotation >= 90 && positiveRotation < 180 && z > 6) ||
				(positiveRotation >= 180 && positiveRotation < 270 && z % 1 == 0) ||
				(positiveRotation >= 270 && positiveRotation < 360 && z < 3)
				) //Fire left
			{
				((Cannon*)& w)->Fire(glm::vec2(-1 + rotation / 90, 0 - rotation / 90));
			}
			else //Fire right
			{
				((Cannon*)& w)->Fire(glm::vec2(1 - rotation / 90, 0 + rotation / 90));
			}
			w.Fire();
			++z;
		}
	}
#pragma endregion
	#pragma region Direction Change
	if (rotationTimer > 0)
	{
		--rotationTimer;
		rotation = rotationValues[rotationIteration] > 0 ? rotation + rotationFactor : rotation - rotationFactor;
		positiveRotation = rotation < 0 ? 360 - rotation : rotation;
		if (rotationTimer <= 0)
		{
			int i = rotation < 0 ? rotation + 360 : rotation;
			switch (i)
			{
			case 0:
				speed = { -baseSpeed, 0 };
				break;
			case 90:
				speed = { 0, -baseSpeed };
				break;
			case 180:
				speed = { baseSpeed, 0 };
				break;
			case 270:
				speed = { 0, baseSpeed };
				break;
			}
			++rotationIteration;
			if (rotationIteration == rotationValues.size()) {
				rotationIteration = 0;
			}
			movementTimer = speed.x == 0 ? movementTimerResetY : movementTimerResetX;
		}
	}
	else if (movementTimer <= 0 && rotationTimer <= 0 && speed.x != speed.y)
	{
		if (rotationValues[rotationIteration] == 0)
		{
			movementTimer = speed.x == 0 ? movementTimerResetY : movementTimerResetX;
			++rotationIteration;
			if (rotationIteration == rotationValues.size()) {
				rotationIteration = 0;
			}
		}
		else
		{
			speed = glm::vec2(0, 0);
			rotationTimer = rotationTimerReset;
		}
	}
	else if (movementTimer > 0)
	{
		--movementTimer;
	}
	#pragma endregion

}

double CannonlordAI::getRotation()
{
	return rotation;
}

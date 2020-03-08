#include "CannonlordAI.h"
#include "Blank.h"
#include "BasicBody.h"

CannonlordAI::CannonlordAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		Blank(),	Cannon(),	 BasicBody(), BasicBody(), Cannon(), BasicBody(), BasicBody(), Cannon(), Blank(),
		Cannon(),	BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon(),
		BasicBody(),BasicBody(), Blank(), Blank(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		BasicBody(),BasicBody(), Blank(), Blank(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		Cannon(),	BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon(),
		Blank(),	Cannon(),	 BasicBody(), BasicBody(), Cannon(), BasicBody(), BasicBody(), Cannon(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(40, //Enemy is 360px by 240px
	build, 9, 6), 300, //Will tweak if 50 health proves to be too much or too little
		this, transform, "Cannonlord");
	speed.x = -baseSpeed;
	target = glm::vec2(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT / 2);

	#pragma region Cannon Setup
	int z = 0;
	for (Weapon w : parent->GetFrame()->GetWeapons())
	{
		if (z < 3) {
			topCannons.push_back((Cannon&) w);
		}
		else if (z > 6) {
			bottomCannons.push_back((Cannon&) w);
		}
		else if (z % 2 == 1) {
			leftCannons.push_back((Cannon&) w);
		}
		else {
			rightCannons.push_back((Cannon&) w);
		}
		++z;
	}
	#pragma endregion

}

CannonlordAI::~CannonlordAI()
{
}

void CannonlordAI::SecondaryFunction()
{
	#pragma region Direction Change
	if (rotationTimer > 0)
	{
		--rotationTimer;
		rotation = rotationValues[rotationIteration] > 0 ? rotation + rotationFactor : rotation - rotationFactor;
		positiveRotation = rotation;
		while (positiveRotation >= 360 || positiveRotation < 0) {
			positiveRotation = positiveRotation >= 360 ? positiveRotation - 360 : positiveRotation + 360;
		}
		localRotation = positiveRotation;
		while (localRotation >= 90) {
			localRotation -= 90;
		}
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
	#pragma region Fire Cannons
	--attackCooldown;
	if (attackCooldown <= 0)
	{
		//Some sort of error around here...
		if (positiveRotation >= 0 && positiveRotation < 90) {
			cannonlordFire(topCannons, bottomCannons, leftCannons, rightCannons);
		}
		else if (positiveRotation >= 90 && positiveRotation < 180) {
			cannonlordFire(leftCannons, rightCannons, bottomCannons, topCannons);
		}
		else if (positiveRotation >= 180 && positiveRotation < 270) {
			cannonlordFire(bottomCannons, topCannons, rightCannons, leftCannons);
		}
		else if (positiveRotation >= 270 && positiveRotation < 360) {
			cannonlordFire(rightCannons, leftCannons, topCannons, bottomCannons);
		}
		attackCooldown = attackCooldownReset;
	}
	#pragma endregion
}

double CannonlordAI::getRotation()
{
	return rotation;
}

void CannonlordAI::cannonlordFire(std::vector<Cannon> up, std::vector<Cannon> down, std::vector<Cannon> left, std::vector<Cannon> right)
{
	for (Cannon w : up) {
		w.Fire(Vector2(2 * (0 + localRotation / 90), 2 * (-1 + localRotation / 90)));
	}
	for (Cannon w : down) {
		w.Fire(Vector2(2 * (0 - localRotation / 90), 2 * (1 - localRotation / 90)));
	}
	for (Cannon w : left) {
		w.Fire(Vector2(2 * (-1 + localRotation / 90), 2 * (0 - localRotation / 90)));
	}
	for (Cannon w : right) {
		w.Fire(Vector2(2 * (1 - localRotation / 90), 2 * (0 + localRotation / 90)));
	}
}

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
	parent = Enemy(Frame(50, //Enemy is 450px by 300px
	build, 9, 6), 50, //Will tweak if 50 health proves to be too much or too little
		this, transform);
	speed.x = -baseSpeed;
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
		for (Weapon w : parent.GetFrame().GetWeapons())
		{
			w.Fire();
		}
	}
#pragma endregion
	#pragma region Direction Change
	if (rotationTimer > 0)
	{
		--rotationTimer;
		rotation = rotationValues[rotationIteration] > 0 ? rotation + rotationFactor : rotation - rotationFactor;
		if (rotationTimer == 0)
		{
			rotationTimer = rotationTimerReset;
			int i = rotation < 0 ? rotation + 360 : rotation;
			switch (i)
			{
			case 0:
				speed = { -baseSpeed, 0 };
				break;
			case 90:
				speed = { 0, baseSpeed };
				break;
			case 180:
				speed = { baseSpeed, 0 };
				break;
			case 270:
				speed = { 0, -baseSpeed };
				break;
			}
			++rotationIteration;
			movementTimer = movementTimerReset;
		}
	}
	else if (movementTimer <= 0 && rotationTimer <= 0 && speed.x != speed.y)
	{
		if (rotationValues[rotationIteration] == 0)
		{
			movementTimer = movementTimerReset;
			++rotationIteration;
		}
		else
		{
			speed = { 0, 0 };
			rotationTimer = rotationTimerReset;
		}
	}
	else if (movementTimer > 0)
	{
		--movementTimer;
	}
	#pragma endregion

}

#include "BlasterSkiffAI.h"
#include "BasicBody.h"
#include "IndesBody.h"
#include "Blank.h"
#include "Game.h"

BlasterSkiffAI::BlasterSkiffAI(glm::vec2 transform)
{
	parent = Enemy(Frame(10, //Enemy is ?px by ?px
#pragma region Frame Construction
		{
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank()},
			{BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false)},
			{BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false)},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank()},
			{Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank()}
		}
#pragma endregion
	), 50, //Will tweak if 50 health proves to be too much or too little
	this, transform);
	speed.y = 0.05f; //Tweak this number later
}

BlasterSkiffAI::~BlasterSkiffAI()
{
}

void BlasterSkiffAI::SecondaryFunction()
{
	//Change Movement Direction
	if (parent.GetTransform().y == topBouncePoint || parent.GetTransform().y == bottomBouncePoint)
	{
		speed.y = -speed.y;
	}
	//Shoot
	if (firingCooldown > 0)
	{
		--firingCooldown;
		if (firingCooldown <= 0)
		{
			parent.GetFrame().GetWeapon(firingIteration);
			++firingIteration;
			if (parent.GetFrame().GetWeapons().size == firingIteration)
			{
				firingIteration = 0;
			}
			firingCooldown = firingCooldownReset;
		}
	}

	//Spawn Enemies
	if (parent.GetTransform().y == topBouncePoint + (bottomBouncePoint - topBouncePoint) / 2)
	{
		TheGame.GetInstance().Instantiate(RamAI, glm::vec2{ TheGame.GetInstance().OffScreenRight, TheGame.GetInstance().OffScreenTop});
	}
}

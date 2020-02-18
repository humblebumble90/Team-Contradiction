#include "BlasterSkiffAI.h"
#include "BasicBody.h"
#include "IndesBody.h"
#include "Blank.h"
#include "Game.h"
#include "MissileLauncher.h"

BlasterSkiffAI::BlasterSkiffAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
			BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false),
			BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank(),
			Blank(), MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(), Blank(), Blank(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(50, //Enemy is 800px by 400px
	build, 8, 16), 50, //Will tweak if 50 health proves to be too much or too little
	this, transform, "BlasterSkiff");
	speed.y = 0.05f; //Tweak this number later
}

BlasterSkiffAI::~BlasterSkiffAI()
{
}

void BlasterSkiffAI::SecondaryFunction()
{
	//Change Movement Direction
	if (parent->getPosition().y == topBouncePoint || parent->getPosition().y == bottomBouncePoint)
	{
		speed.y = -speed.y;
	}
	//Shoot
	if (firingCooldown > 0)
	{
		--firingCooldown;
		if (firingCooldown <= 0)
		{
			parent->GetFrame()->GetWeapon(firingIteration);
			++firingIteration;
			if (parent->GetFrame()->GetWeapons().size() == firingIteration)
			{
				firingIteration = 0;
			}
			firingCooldown = firingCooldownReset;
		}
	}

	//Spawn Enemies
	if (parent->getPosition().y == topBouncePoint + (bottomBouncePoint - topBouncePoint) / 2)
	{
		//TheGame::Instance() TODO: Add this back
	}
}

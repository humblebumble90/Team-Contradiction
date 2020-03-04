#include "FirebrandAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "IndesBody.h"
#include "Game.h"
#include "Flamethrower.h"
#include "Cannon.h"
#include "MissileLauncher.h"

FirebrandAI::FirebrandAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		MissileLauncher(), Flamethrower(), Flamethrower(), Flamethrower(), Flamethrower(), Flamethrower(), Blank(), Blank(),
		MissileLauncher(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
		Flamethrower(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
		Cannon(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
		Cannon(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false),
		Cannon(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false),
		Cannon(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false),
		Cannon(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false),
		Cannon(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
		Flamethrower(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
		MissileLauncher(), BasicBody(), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
		MissileLauncher(), Flamethrower(), Flamethrower(), Flamethrower(), Flamethrower(), Flamethrower(), Blank(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(40, //Enemy is 320px by 480px
	build, 8, 12), 50, //Will tweak if 50 health proves to be too much or too little
		this, transform, "Firebrand");
	speed.y = baseSpeed; //Tweak this number later

	//Fire Flamethrowers
	for (Weapon w : parent->GetFrame()->GetWeapons())
	{
		if (w.getName()=="Flamethrower") {
			w.Fire();
		}
	}

	target = glm::vec2(1000, Config::SCREEN_HEIGHT/2);
}

FirebrandAI::~FirebrandAI()
{
}

void FirebrandAI::SecondaryFunction()
{
	#pragma region Cooldowns - Turn these into coroutines
	#pragma region Cannons
	if (cannonCooldown > 0 && ramCooldown == 0)
	{
		--cannonCooldown;
	}
#pragma endregion
	#pragma region Missiles
	if (ramCooldown == 0) {
		--missileCooldown;
		if (missileCooldown <= 0)
		{
			missileCooldown = missileCooldownReset;
			for (Weapon w : parent->GetFrame()->GetWeapons())
			{
				if (w.getName() == "MissileLauncher") {
					w.Fire();
				}
			}
		}
	}
#pragma endregion
	#pragma region Ramming
	if (ramCooldown != 0)
	{
		if (ramCooldown > 0)
		{
			--ramCooldown;
			if (ramCooldown <= 0)
			{
				speed.x = -speed.x;
				ramCooldown = -ramCooldownReset;
			}
		}
		else if (ramCooldown < 0)
		{
			++ramCooldown;
			if (ramCooldown > 0)
			{
				ramCooldown = 0;
			}
			if (ramCooldown == 0)
			{
				speed.x = 0;
				hasTarget = false;
			}
		}
	}
	#pragma endregion
	#pragma endregion
	if (!hasTarget)
	{
		//Get target
		moveTarget = TheGame::Instance()->getPlayerPosition().y;
		speed.y = parent->getPosition().y > moveTarget ? -baseSpeed : baseSpeed;
		hasTarget = true;
	}
	else if ((speed.y <= 0 && parent->getPosition().y <= moveTarget) || (speed.y > 0 && parent->getPosition().y >= moveTarget))
	{
		if (speed.y != 0)
		{
			speed.y = 0;
		}

		if (ramCounter <= 0)
		{
			ramCounter = ramCounterReset;
			ramCooldown = ramCooldownReset;
			speed.x = -baseSpeed*3;
		}
		else if (cannonCooldown <= 0)
		{
			cannonCooldown = cannonCooldownReset;
			for (Weapon w : parent->GetFrame()->GetWeapons())
			{
				if (w.getName()=="Cannon") {
					w.Fire();
				}
			}
			hasTarget = false;
			--ramCounter;
		}
	}
	else if (speed.y == 0) {
		speed.y = parent->getPosition().y > moveTarget ? -baseSpeed : baseSpeed;
	}
}

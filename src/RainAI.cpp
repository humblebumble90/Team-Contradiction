#include "RainAI.h"
#include "BasicBody.h"
#include "Cannon.h"
#include "Blank.h"
#include "Config.h"
#include "Game.h"

RainAI::RainAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		Blank(), Blank(), Cannon(), BasicBody(), Cannon(), Blank(), Blank(),
		Blank(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Blank(),
		Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon(),
		BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon(),
		Blank(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Blank(),
		Blank(), Blank(), Cannon(), BasicBody(), Cannon(), Blank(), Blank()
	};
	parent = new Enemy(new Frame(40, //Enemy is 280px by 280px
		build, 7, 7), 50, //Will tweak if 50 health proves to be too much or too little
		this, transform, "Rain");
	speed.y = 10.00f; //Tweak this number later
#pragma endregion
}

RainAI::~RainAI()
{
}

void RainAI::SecondaryFunction()
{
	#pragma region Firing Timer
	if (firingCooldown > 0) {
		--firingCooldown;
	}
	#pragma endregion
	#pragma region Fire (Normal Mode)
	if (firingCooldown <= 0 && firingIteration != rainIteration)
	{
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			w.Fire();
		}
		firingCooldown = firingCooldownReset;
		++firingIteration;
		if (firingIteration == rainIteration) {
			speed.y = -10.00f;
		}
		else
		{
			getNewTarget();
		}
	}
	#pragma endregion
	#pragma region Rain Mode
	else if (firingIteration == rainIteration && parent->getPosition().y - parent->GetFrame()->GridHeight() * parent->GetFrame()->getGridSize() / 2 <= 0)
	{
		#pragma region Movement
		if (speed.x == 0 || parent->getPosition().x + parent->GetFrame()->GridWidth() * parent->GetFrame()->getGridSize() / 2 >= Config::SCREEN_WIDTH)
		{
			speed.x = -10;
		}
		else if (parent->getPosition().x - parent->GetFrame()->GridWidth() * parent->GetFrame()->getGridSize() / 2 <= 0)
		{
			speed.x = 10;
		}
		#pragma endregion
		#pragma region Fire (Rain Mode)
		if (firingCooldown <= 0)
		{
			for (Weapon w : parent->GetFrame()->GetWeapons())
			{
				((Cannon*)&w)->Fire(glm::vec2(0, 1));
			}
			firingCooldown = rainFiringCooldownReset;
		}
		#pragma endregion
		#pragma region End Rain Mode
		--rainCooldown;
		if (rainCooldown <= 0)
		{
			rainCooldown = rainCooldownReset;
			firingIteration = 0;
			if (parent->getPosition().x < target.x) {
				speed.x = -10;
				getNewTarget();
			}
		}
		#pragma endregion
	}
	#pragma endregion
	#pragma region Reset X-Movement
	if (firingIteration != rainIteration && speed.x != 0 && parent->getPosition().x >= target.x)
	{
		speed.x = 0;
	}
	#pragma endregion
	#pragma region Pause Y-Movement
	if ((parent->getPosition().y >= targetLoc.y && speed.y < 0) || (parent->getPosition().y <= targetLoc.y && speed.y > 0))
	{
		speed.y = 0;
	}
	#pragma endregion

}

void RainAI::getNewTarget()
{
	targetLoc = glm::vec2(target.x, TheGame::Instance()->getPlayerPosition().y);
	speed.y = targetLoc.y > parent->getPosition().y ? -10 : 10;
}

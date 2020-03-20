#include "DeathcageAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "Flamethrower.h"
#include "Cannon.h"
#include "Config.h"

DeathcageAI::DeathcageAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Blank(),
		Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), BasicBody(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody(),
		Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), BasicBody(), BasicBody(),
		BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(40, //Enemy is 640px by 720px - NOTE: Deathcage is the height of the screen
	build, 16, 18), 150, //Will tweak if 100 health proves to be too much or too little
		this, transform, "Deathcage");

#pragma region Assocate Cannons
	std::vector<Cannon> Cannons;
	for (Weapon w : parent->GetFrame()->GetWeapons())
	{
		if (w.getName()=="Cannon") {
			Cannons.push_back((Cannon&)w);
		}
	}
	for (int z = 0; z <= cannonMaximum; ++z)
	{
		topCannons.push_back(Cannons[z]);
		bottomCannons.push_back(Cannons[Cannons.size() - 1 - z]);
	}
	for (int z = topCannons.size(); z < Cannons.size() - bottomCannons.size(); ++z)
	{
		centerCannons.push_back(Cannons[z]);
	}
#pragma endregion
	//Fire Flamethrowers
	for (Weapon w : parent->GetFrame()->GetWeapons())
	{
		if (w.getName()=="Flamethrower") {
			w.Fire();
		}
	}

	target = glm::vec2(parent->GetFrame()->getGridSize() * parent->GetFrame()->GridWidth() / 2, Config::SCREEN_HEIGHT / 2);
	entrySpeed = glm::vec2(-10, 0);
	score = 150;
}

DeathcageAI::~DeathcageAI()
{
}

void DeathcageAI::SecondaryFunction()
{
	--attackCooldown;
	if (attackCooldown == 0)
	{
		attackCooldown = attackCooldownReset;
		if (cannonIteration > cannonMaximum)
		{
			centerCannons[centerIteration].Fire();
			centerCannons[centerCannons.size() - 1 - centerIteration].Fire();
			++centerIteration;
			if (centerIteration == centerCannons.size() - centerIteration)
			{
				centerIteration = 0;
				cannonIteration = 0;
			}
		}
		else
		{
			topCannons[cannonIteration].Fire(Vector2(0, 1));
			bottomCannons[cannonIteration].Fire(Vector2(0, -1));
			++cannonIteration;
		}
	}
}

#include "DeathcageAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "Flamethrower.h"
#include "Cannon.h"

DeathcageAI::DeathcageAI(glm::vec2 transform)
{
	parent = Enemy(Frame(50, //Enemy is 800px by 900px - NOTE: Deathcage is the height of the screen
#pragma region Frame Construction
		{
			{BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Blank()},
			{Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), BasicBody(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Flamethrower(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Blank(), Cannon(), BasicBody()},
			{Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), Cannon(), Flamethrower(), Cannon(), BasicBody(), BasicBody()},
			{BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Blank()}
		}
#pragma endregion
	), 100, //Will tweak if 100 health proves to be too much or too little
		this, transform);

#pragma region Assocate Cannons
	std::vector<Weapon> Cannons;
	for (Weapon w : parent.GetFrame().GetWeapons())
	{
		if (typeid(w) == typeid(Cannon)) {
			Cannons.push_back(w);
		}
	}
	for (int z = 0; z <= cannonMaximum; ++z)
	{
		topCannons.push_back(Cannons[z]);
		bottomCannons.push_back(Cannons[Cannons.size() - 1 - z]);
	}
	for (int z = topCannons.size; z < Cannons.size() - bottomCannons.size(); ++z)
	{
		centerCannons.push_back(Cannons[z]);
	}
#pragma endregion
	//Fire Flamethrowers
	for (Weapon w : parent.GetFrame().GetWeapons())
	{
		if (typeid(w) == typeid(Flamethrower)) {
			w.Fire();
		}
	}
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
			if (centerIteration + 1 == centerCannons.size() - 1 - centerIteration)
			{
				centerIteration = 0;
				cannonIteration = 0;
			}
		}
		else
		{
			topCannons[cannonIteration].Fire();
			bottomCannons[cannonIteration].Fire();
			++cannonIteration;
		}
	}
}

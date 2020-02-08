#include "MissileBargeAI.h"
#include "Blank.h"
#include "BasicBody.h"

MissileBargeAI::MissileBargeAI(glm::vec2 transform)
{
	parent = Enemy(Frame(50, //Enemy is 300px by 300px
#pragma region Frame Construction
		{
			{Blank(), MissileLauncher(), MissileLauncher(),MissileLauncher(),MissileLauncher(), Blank()},
			{MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher()},
			{MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher()},
			{MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher()},
			{MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher()},
			{Blank(), MissileLauncher(), MissileLauncher(),MissileLauncher(),MissileLauncher(), Blank()}
		}
#pragma endregion
	), 20, //Will tweak if it proves to be too much or too little
		this, transform);
	speed.y = -0.1;
}

MissileBargeAI::~MissileBargeAI()
{
}

void MissileBargeAI::SecondaryFunction()
{
	if (parent.getPosition().y == topLimit || parent.getPosition().y == bottomLimit)
	{
		speed.y = -speed.y;
	}
	--attackCooldown;
	if (attackCooldown <= 0)
	{
		attackCooldown = attackCooldownReset;
		for (Weapon w : parent.GetFrame().GetWeapons())
		{
			w.Fire();
		}
	}
}

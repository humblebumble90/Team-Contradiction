#include "MissileBargeAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "MissileLauncher.h"

MissileBargeAI::MissileBargeAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		Blank(), MissileLauncher(), MissileLauncher(),MissileLauncher(),MissileLauncher(), Blank(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), MissileLauncher(),
		Blank(), MissileLauncher(), MissileLauncher(),MissileLauncher(),MissileLauncher(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(50, //Enemy is 300px by 300px
	build, 6, 6), 20, //Will tweak if it proves to be too much or too little
		this, transform, "MissileBarge");
	speed.y = -0.1f;
}

MissileBargeAI::~MissileBargeAI()
{
}

void MissileBargeAI::SecondaryFunction()
{
	if (parent->getPosition().y == topLimit || parent->getPosition().y == bottomLimit)
	{
		speed.y = -speed.y;
	}
	--attackCooldown;
	if (attackCooldown <= 0)
	{
		attackCooldown = attackCooldownReset;
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			w.Fire();
		}
	}
}

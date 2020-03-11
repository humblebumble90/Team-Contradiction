#include "MissileBargeAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "MissileLauncher.h"
#include "Config.h"

MissileBargeAI::MissileBargeAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		Blank(), MissileLauncher(),MissileLauncher(), Blank(),
		MissileLauncher(), BasicBody(),BasicBody(), MissileLauncher(),
		MissileLauncher(), BasicBody(),BasicBody(), MissileLauncher(),
		Blank(), MissileLauncher(),MissileLauncher(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(60, //Enemy is 240px by 240px
	build, 4, 4), 15, //Will tweak if it proves to be too much or too little
		this, transform, "MissileBarge");
	speed.y = -8.00f;
	topLimit = parent->GetFrame()->getGridSize() * parent->GetFrame()->GridHeight() / 2;
	bottomLimit = Config::SCREEN_HEIGHT - topLimit;
	target = glm::vec2(Config::SCREEN_WIDTH * 3 / 4, Config::SCREEN_HEIGHT / 2);
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

#include "BlasterSkiffAI.h"
#include "BasicBody.h"
#include "IndesBody.h"
#include "Blank.h"
#include "Game.h"
#include "MissileLauncher.h"
#include "RamAI.h"

BlasterSkiffAI::BlasterSkiffAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(),		  Blank(),			Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(),			Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(),			Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(),		  IndesBody(false), Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(),		  IndesBody(false), IndesBody(false),
			BasicBody(),IndesBody(false), IndesBody(false),	  IndesBody(false), Blank(),		  Blank(),			IndesBody(false),
			BasicBody(),IndesBody(false), IndesBody(false),   IndesBody(false), Blank(),		  Blank(),			IndesBody(false),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(),		  IndesBody(false), IndesBody(false),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(),		  IndesBody(false), Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), IndesBody(false), Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(),			Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), IndesBody(false), Blank(),			Blank(),
			Blank(),	MissileLauncher(), MissileLauncher(), IndesBody(false), Blank(),		  Blank(),			Blank(),
	};
	#pragma endregion
	parent = new Enemy(new Frame(45.714285, //Enemy is 320px by 640px
	build, 7, 14), 25,
	this, transform, "BlasterSkiff");
	speed.y = 1.00f; //Tweak this number later
	topBouncePoint = parent->GetFrame()->getGridSize() * parent->GetFrame()->GridHeight() / 2;
	bottomBouncePoint = Config::SCREEN_HEIGHT - topBouncePoint;
	spawnPoint = 25;
	target = glm::vec2(Config::SCREEN_WIDTH - parent->GetFrame()->getGridSize() * parent->GetFrame()->GridWidth() / 2, Config::SCREEN_HEIGHT/2);

}

BlasterSkiffAI::~BlasterSkiffAI()
{
}

void BlasterSkiffAI::SecondaryFunction()
{
	//Change Movement Direction
	if (parent->getPosition().y <= topBouncePoint || parent->getPosition().y >= bottomBouncePoint)
	{
		speed.y = -speed.y;
	}
	//Shoot
	if (firingCooldown > 0)
	{
		--firingCooldown;
		if (firingCooldown <= 0)
		{
			parent->GetFrame()->GetWeapon(firingIteration).Fire();
			++firingIteration;
			if (parent->GetFrame()->GetWeapons().size() == firingIteration)
			{
				firingIteration = 0;
			}
			firingCooldown = firingCooldownReset;
		}
	}

	//Spawn Enemies
	if (parent->getPosition().y == Config::SCREEN_HEIGHT/2)
	{
		TheGame::Instance()->spawnEnemy(new RamAI(glm::vec2(Config::SCREEN_WIDTH + 25, spawnPoint)));
		spawnPoint = Config::SCREEN_HEIGHT-spawnPoint;
	}
}

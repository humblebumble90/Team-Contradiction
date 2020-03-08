#include "Flamethrower.h"
#include "Game.h"
#include "FlameThrowerWeapon.h"

Flamethrower::Flamethrower()
{
	name = "Flamethrower";
}

Flamethrower::~Flamethrower()
{
}

void Flamethrower::Fire()
{
	if (getParent()->getParent()->getName() == "Player")
	{
		TheGame::Instance()->spawnPlayerWeapon(new FlameThrowerWeapon(getPosition()));
	}

	/*else
	{
		TheGame::Instance()->spawnEnemy(new FirebrandAI(getPosition()));
	}*/
}

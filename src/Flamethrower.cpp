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
		flameThrower = new FlameThrowerWeapon(getPosition());
        TheGame::Instance()->spawnPlayerWeapon(flameThrower);


	}

	/*else
	{
		TheGame::Instance()->spawnEnemy(new FirebrandAI(getPosition()));
	}*/
}

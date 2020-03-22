#include "Flamethrower.h"
#include "Game.h"
#include "FlameThrowerWeapon.h"
#include "EnemyFlamethrowerAI.h"
Flamethrower::Flamethrower()
{
	name = "Flamethrower";
	//m_pPlayerShip = new PlayerShip();
}

Flamethrower::~Flamethrower()
{
}

void Flamethrower::Fire()
{
	if (getParent()->getParent()->getName() == "Player")
	{
		flamethrower = new FlameThrowerWeapon(getPosition());
        TheGame::Instance()->spawnPlayerWeapon(flamethrower);

	}

	/*else
	{
		TheGame::Instance()->spawnEnemy(new EnemyFlamethrowerAI());
	}*/
}

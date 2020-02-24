#include "MissileLauncher.h"
#include "Game.h"
#include "EnemyMissileAI.h"

MissileLauncher::MissileLauncher()
{
	name = "MissileLauncher";
}

MissileLauncher::~MissileLauncher()
{
}

void MissileLauncher::Fire()
{
	//instantiates an object of WeaponMissile and draws it on the screen
	if (getParent()->getParent()->getName() == "Player") {
		m_pWeaponMissile = new WeaponMissile();
		m_pWeaponMissile->draw();
	}
	else {
		EnemyMissileAI e = EnemyMissileAI(getPosition());
	}
}



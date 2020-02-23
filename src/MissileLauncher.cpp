#include "MissileLauncher.h"

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
	m_pWeaponMissile = new WeaponMissile();
	m_pWeaponMissile->draw();
}



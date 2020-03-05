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
	//TODO: Add a Cooldown, and a method of firing it

	if (getParent()->getParent()->getName() == "Player") {
		TheGame::Instance()->spawnPlayerWeapon(new WeaponMissile(getPosition(), glm::vec2(10, 0)));
	}
	else {
		TheGame::Instance()->spawnEnemy(new EnemyMissileAI(getPosition()));
	}
}

void MissileLauncher::Fire(glm::vec2 trajectory)
{
	if (getParent()->getParent()->getName() == "Player") {
		//TODO: WeaponMissile needs some sort of trajectory handling
	}
	else {
		TheGame::Instance()->spawnEnemy(new EnemyMissileAI(getPosition(), getPosition() + trajectory));
	}
}



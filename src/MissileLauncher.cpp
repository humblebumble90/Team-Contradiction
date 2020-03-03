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
		//TODO: Instead of creating an m_pWeaponMissile, this method should add a WeaponMissile to the LevelScene,
		//likely by calling a method in Game.cpp to call a method of the same name in LevelScene
		m_pWeaponMissile = new WeaponMissile();
		m_pWeaponMissile->draw();
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



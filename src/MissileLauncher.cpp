#include "MissileLauncher.h"
#include "Game.h"
#include "EnemyMissileAI.h"
#include "WeaponMissile.h"

MissileLauncher::MissileLauncher()
{
	name = "MissileLauncher";
}

MissileLauncher::~MissileLauncher()
{
}

void MissileLauncher::Fire()
{
	if (getParent()->getParent()->getName() == "Player") {
		glm::vec2 s;
		int i = getID().y;
		switch (i) {
		case 0:
			s = glm::vec2(5, -5);
			break;
		case 1:
			s = glm::vec2(10, 0);
			break;
		case 2:
			s = glm::vec2(5, 5);
			break;
		}
		WeaponMissile* wp = new WeaponMissile(getPosition(), s);
		wp->start();
		TheGame::Instance()->spawnPlayerWeapon(wp);
	}
	else {
		TheGame::Instance()->spawnEnemy(new EnemyMissileAI(getPosition()));
	}
}

void MissileLauncher::Fire(glm::vec2 trajectory)
{
	if (getParent()->getParent()->getName() != "Player") {
		TheGame::Instance()->spawnEnemy(new EnemyMissileAI(getPosition(), getPosition() + trajectory));
	}
}



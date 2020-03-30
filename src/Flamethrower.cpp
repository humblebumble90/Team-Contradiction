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
		
		FlameThrowerWeapon* m_pFlamethrower;
		m_pFlamethrower = new FlameThrowerWeapon(Position());
		
        TheGame::Instance()->spawnPlayerWeapon(flamethrower);
		//m_pFlamethrower->update();

	}

	else
	{
		TheGame::Instance()->spawnEnemy(new EnemyFlamethrowerAI(getPosition()));
	}
}

glm::vec2 Flamethrower::Position()
{
	int iD = getID().y;

	glm::vec2 position;

	switch (iD)
	{
	case 0:
		position = glm::vec2(this->getPosition().x + 1.0f, this->getPosition().y - 1.0f);
		return position;
		break;
	case 1:
		position = glm::vec2(this->getPosition().x + 1.0f, this->getPosition().y);
		return position;
		break;
	case 2:
		position = glm::vec2(this->getPosition().x + 1.0f, this->getPosition().y + 1.0f);
		return position;
		break;
	}


}

#include "Cannon.h"
#include "Cannonball.h"
#include "EnemyCannonballAI.h"
#include "Game.h"
Cannon::Cannon()
{
	name = "Cannon";
}

Cannon::~Cannon()
{
}

void Cannon::Fire()
{

	if (getParent()->getParent()->getName() == "Player")
	{
		glm::vec2 velocity;
		int y = getID().y;

		switch (y)
		{
		case 0:

			velocity = glm::vec2(4.0, -4.0f);
			break;

		case 1:

			velocity = glm::vec2(8.0f, 0.0f);
			break;

		case 2:

			velocity = glm::vec2(4.0f, 4.0f);
			break;
		}
		TheGame::Instance()->spawnPlayerWeapon(new Cannonball(getPosition(), velocity));
	}

	else
	{
		TheGame::Instance()->spawnEnemy(new EnemyCannonballAI(getPosition(), glm::vec2(-1, 0)));
	}

}
void Cannon::Fire(Vector2 direction)
{
	if (getParent()->getParent()->getName() != "Player")
	{
		TheGame::Instance()->spawnEnemy(new EnemyCannonballAI(getPosition(), direction));
	}

	//TheGame::Instance()->spawnEnemy(new FirebrandAI(getPosition()+velocity));

	//this method is the same as Fire(), however, the projectile will travel in the specified direction
	//e.g.	0,0 will not travel
	//		0,1 will travel down
	//		-1,0 will travel left
	//		etc.
}

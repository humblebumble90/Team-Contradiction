#include "Cannon.h"
#include "CannonBall.h"
#include "CannonBargeAI.h"
#include "FirebrandAI.h"
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

			velocity = glm::vec2(5.0, -5.0f);
			break;

		case 1:

			velocity = glm::vec2(8.0f, 0.0f);
			break;

		case 2:

			velocity = glm::vec2(5.0f, 5.0f);
			break;
		}
		TheGame::Instance()->spawnPlayerWeapon(new CannonBall(getPosition(), velocity));
	}

	else
	{
		TheGame::Instance()->spawnEnemy(new FirebrandAI(getPosition()));
	}

}
void Cannon::Fire(glm::vec2 direction)
{
	glm::vec2 velocity;

	if (getParent()->getParent()->getName() != "Player")
	{
		if (direction.x == 0.0f && direction.y == 1.0f)
		{
			velocity = glm::vec2(0.0f, 8.0f); // travels up
		}

		else if (direction.x == 0.0f && direction.y == -1.0f)
		{
			velocity = glm::vec2(0.0f, -8.0f); // travels down
		}

		else if (direction.x == 1.0f && direction.y == 0.0f)
		{
			velocity = glm::vec2(8.0f, 0.0f); // travels right
		}

		else if (direction.x == -1.0f && direction.y == 0.0f)
		{
			velocity = glm::vec2(-8.0f, 0.0f); // travels left
		}
	}

	//TheGame::Instance()->spawnEnemy(new FirebrandAI(getPosition()+velocity));

	//this method is the same as Fire(), however, the projectile will travel in the specified direction
	//e.g.	0,0 will not travel
	//		0,1 will travel down
	//		-1,0 will travel left
	//		etc.
}

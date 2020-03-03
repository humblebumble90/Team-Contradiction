#include "DiagonAI.h"
#include "Config.h"
#include "BasicBody.h"
#include "Cannon.h"

DiagonAI::DiagonAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		BasicBody(), BasicBody(), BasicBody(),
		Cannon(), BasicBody(), BasicBody(),
		BasicBody(), BasicBody(), BasicBody()
	};
#pragma endregion
	parent = new Enemy(new Frame(16.666667, //Enemy is 50px by 50px
		build, 3, 3), 1, this, transform, "Diagon");
	float tX = Config::SCREEN_WIDTH/2;
	float tY = Config::SCREEN_HEIGHT/2;
	float xDif = abs(parent->getPosition().x - tX), yDif = abs(parent->getPosition().y - tY);
	bool xIsCloser = xDif > yDif;
	switch (xIsCloser)
	{
	case true:
		speed.x = baseSpeed;
		speed.y = yDif / xDif * baseSpeed;
		break;
	case false:
		speed.y = baseSpeed;
		speed.x = xDif / yDif * baseSpeed;
		break;
	}
	speed.x = parent->getPosition().x > tX ? -speed.x : speed.x;
	speed.y = parent->getPosition().y > tY ? -speed.y : speed.y;
}

DiagonAI::~DiagonAI()
{
}

void DiagonAI::PrimaryFunction()
{
	--firingCooldown;
	if (firingCooldown <= 0) {
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			w.Fire();
		}
		firingCooldown = firingCooldownReset;
	}
}

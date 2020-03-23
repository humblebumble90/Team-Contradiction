#include "DiagonAI.h"
#include "Config.h"
#include "BasicBody.h"
#include "Cannon.h"

DiagonAI::DiagonAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		BasicBody(), BasicBody(),
		Cannon(), BasicBody(),
	};
#pragma endregion
	parent = new Enemy(new Frame(25, //Enemy is 50px by 50px
		build, 2, 2), 1, this, transform, "Diagon");
	baseSpeed = 5.00f;
	score = 100;
	Initialize(glm::vec2(Config::SCREEN_WIDTH / 2, Config::SCREEN_HEIGHT / 2));
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

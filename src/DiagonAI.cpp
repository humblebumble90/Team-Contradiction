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

#include "CannoneerAI.h"
#include "BasicBody.h"
#include "Cannon.h"
CannoneerAI::CannoneerAI(glm::vec2 transform)
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
		build, 3, 3), 1, this, transform, "Cannoneer");
	speed.x = -5.00f; //Tweak this number later
}

CannoneerAI::~CannoneerAI()
{
}

void CannoneerAI::PrimaryFunction()
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

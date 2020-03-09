#include "CannoneerAI.h"
#include "BasicBody.h"
#include "Cannon.h"
CannoneerAI::CannoneerAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		BasicBody(), BasicBody(),
		Cannon(), BasicBody()
	};
#pragma endregion
	parent = new Enemy(new Frame(25, //Enemy is 50px by 50px
		build, 2, 2), 1, this, transform, "Cannoneer");
	speed.x = -4.00f; //Tweak this number later
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

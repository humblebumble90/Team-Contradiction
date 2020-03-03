#include "BlastAI.h"
#include "BasicBody.h"
#include "MissileLauncher.h"

BlastAI::BlastAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		MissileLauncher(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody()
	};
#pragma endregion
	parent = new Enemy(new Frame(10, //Enemy is 50px by 50px
		build, 5, 5), 1, this, transform, "Blast");
	speed.x = -4.00f; //Tweak this number later
}

BlastAI::~BlastAI()
{
}

void BlastAI::PrimaryFunction()
{
	--firingCooldown;
	if (firingCooldown <= 0) {
		std::vector<MissileLauncher*> weapons;
		float z = -1.0f;
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			((MissileLauncher*)&w)->Fire(glm::vec2(0, z));
			z += 0.5f;
		}
		firingCooldown = firingCooldownReset;
	}
}

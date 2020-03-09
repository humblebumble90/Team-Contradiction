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
		MissileLauncher(), BasicBody(), BasicBody(),
	};
#pragma endregion
	parent = new Enemy(new Frame(15, //Enemy is 75px by 75px
		build, 3, 5), 1, this, transform, "Blast");
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
		int z = -4;
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			float x;
			if (abs(z) == 4) {
				x = -2;
			}
			else if (abs(z) == 0) {
				x = -4;
			}
			else {
				x = -3;
			}
			((MissileLauncher*)&w)->Fire(glm::vec2(x, z));
			z += 2;
		}
		firingCooldown = firingCooldownReset;
	}
}

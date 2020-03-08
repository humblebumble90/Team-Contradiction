#include "BlastAI.h"
#include "BasicBody.h"
#include "MissileLauncher.h"

BlastAI::BlastAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody(), BasicBody(), BasicBody()
	};
#pragma endregion
	parent = new Enemy(new Frame(15, //Enemy is 75px by 75px
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
			float x;
			if (abs(z) == 1) {
				x = -0.5f;
			}
			else if (abs(z) == 0) {
				x = -1;
			}
			else {
				x = -0.75f;
			}
			((MissileLauncher*)&w)->Fire(glm::vec2(x, z));
			z += 0.5f;
		}
		firingCooldown = firingCooldownReset;
	}
}

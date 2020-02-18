#include "ZigzagAI.h"
#include "BasicBody.h"
#include "MissileLauncher.h"
ZigzagAI::ZigzagAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		BasicBody(), BasicBody(), BasicBody(),
		BasicBody(), BasicBody(), BasicBody(),
		MissileLauncher(), BasicBody(), BasicBody()
	};
	#pragma endregion
	parent = new Enemy(new Frame(16.666667, //Enemy is 50px by 50px
	build,3,3), 1, this, transform);
	speed.x = speed.y = -0.075f; //Tweak this number later
}

ZigzagAI::~ZigzagAI()
{
}

void ZigzagAI::PrimaryFunction()
{
	if (bounceTimer > 0)
	{
		--bounceTimer;
		if (bounceTimer <= 0)
		{
			speed.y = -speed.y;
			for (Weapon w : parent->GetFrame()->GetWeapons())
			{
				w.Fire();
			}
			bounceTimer = bounceTimerReset;
		}
	}
}

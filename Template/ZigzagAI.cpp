#include "ZigzagAI.h"
#include "BasicBody.h"
ZigzagAI::ZigzagAI(float transform[2])
{
	parent = Enemy(Frame(10, //Enemy is 30px by 30px
		#pragma region Frame Construction
		{
			{BasicBody(), BasicBody(), BasicBody()},
			{MissileLauncher(), BasicBody(), BasicBody()},
			{BasicBody(), BasicBody(), BasicBody()}
		}
		#pragma endregion
		), 1, this, transform);
	speed[0] = speed[1] = 0.075f; //Tweak this number later
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
			speed[1] = -speed[1];
			for (Weapon w : parent.GetFrame().GetWeapons())
			{
				w.Fire();
			}
			bounceTimer = bounceTimerReset;
		}
	}
}

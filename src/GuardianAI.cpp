#include "GuardianAI.h"
#include "BasicBody.h"
#include "Cannon.h"
#include "Config.h"

GuardianAI::GuardianAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		BasicBody(), BasicBody(),
		Cannon(), BasicBody(),
		BasicBody(), BasicBody()
	};
#pragma endregion
	parent = new Enemy(new Frame(15, //Enemy Hitbox is 30px by 45px (sprite is 30x60)
		build, 2, 4), 1, this, transform, "Guardian");
	speed.y = -5.00f; //Tweak this number later
}

GuardianAI::~GuardianAI()
{
}

void GuardianAI::PrimaryFunction()
{
	#pragma region Movement
	if (GetParent()->getPosition().y + 30 <= Config::SCREEN_HEIGHT) {
		if (GetParent()->getPosition().y == 30 || GetParent()->getPosition().y + 30 == Config::SCREEN_HEIGHT) {
			speed.y = -speed.y;
		}
	}
	#pragma endregion
	#pragma region Firing
	--firingCooldown;
	if (firingCooldown <= 0) {
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			w.Fire();
		}
		firingCooldown = firingCooldownReset;
	}
	#pragma endregion
}

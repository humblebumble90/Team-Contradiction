#include "CannonBargeAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "Cannon.h"
#include "Config.h"

CannonBargeAI::CannonBargeAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		Blank(), Cannon(), Cannon(), Blank(),
		Cannon(), BasicBody(), BasicBody(), Cannon(),
		Cannon(), BasicBody(), BasicBody(), Cannon(),
		Blank(), Cannon(), Cannon(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(60, //Enemy is 240px by 240px
	build, 4, 4), 20, //Will tweak if it proves to be too much or too little
		this, transform, "CannonBarge");
	target = glm::vec2(Config::SCREEN_WIDTH/2, Config::SCREEN_HEIGHT/2);
}

CannonBargeAI::~CannonBargeAI()
{
}

void CannonBargeAI::SecondaryFunction()
{
	++rotation;
	if (rotation >=90)
	{
		rotation -= 90;
	}
	--attackCooldown;
	if (attackCooldown <= 0)
	{
		attackCooldown = attackCooldownReset;
		int z = 0;
		for (Weapon w : parent->GetFrame()->GetWeapons())
		{
			if (z < 2) {
				((Cannon*)& w)->Fire(Vector2(0 + rotation / 90, -1 + rotation / 90));
			}
			else if (z > 5) {
				((Cannon*)& w)->Fire(Vector2(0 - rotation / 90, 1 - rotation / 90));
			}
			else if (z % 2 == 0) {
				((Cannon*)& w)->Fire(Vector2(-1 + rotation / 90, 0 - rotation / 90));
			}
			else {
				((Cannon*)& w)->Fire(Vector2(1 - rotation / 90, 0 + rotation / 90));
			}
			++z;
		}
	}
}

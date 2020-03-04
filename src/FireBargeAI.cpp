#include "FireBargeAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "Flamethrower.h"
#include "Config.h"

FireBargeAI::FireBargeAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
	#pragma region Frame Construction
	{
		Blank(), Flamethrower(), Flamethrower(),Flamethrower(),Flamethrower(), Blank(),
		Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower(),
		Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower(),
		Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower(),
		Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower(),
		Blank(), Flamethrower(), Flamethrower(),Flamethrower(),Flamethrower(), Blank()
	};
	#pragma endregion
	parent = new Enemy(new Frame(40, //Enemy is 240px by 240px
	build, 6, 6), 20, //Will tweak if it proves to be too much or too little
		this, transform, "FireBarge");
	speed.y = -baseSpeed; //Tweak this number later

	//Fire Flamethrowers
	for (Weapon w : parent->GetFrame()->GetWeapons())
	{
		w.Fire();
	}

	topLimit = parent->GetFrame()->getGridSize() * parent->GetFrame()->GridHeight() / 2;
	bottomLimit = Config::SCREEN_HEIGHT - topLimit;
	leftLimit = parent->GetFrame()->getGridSize() * parent->GetFrame()->GridWidth() / 2;
	rightLimit = Config::SCREEN_WIDTH - leftLimit;
	target = glm::vec2(rightLimit, Config::SCREEN_HEIGHT / 2);
}

FireBargeAI::~FireBargeAI()
{
}

void FireBargeAI::SecondaryFunction()
{
	if (parent->getPosition().y <= topLimit && speed.x == 0)
	{
		speed.y = 0;
		speed.x = -baseSpeed;
	}
	else if (parent->getPosition().y >= bottomLimit && speed.x == 0)
	{
		speed.y = 0;
		speed.x = baseSpeed;
	}
	else if (parent->getPosition().x <= leftLimit && speed.y == 0)
	{
		speed.y = baseSpeed;
		speed.x = 0;
	}
	else if (parent->getPosition().x >= rightLimit && speed.y == 0)
	{
		speed.y = -baseSpeed;
		speed.x = 0;
	}
}

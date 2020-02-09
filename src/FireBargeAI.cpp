#include "FireBargeAI.h"
#include "Blank.h"
#include "BasicBody.h"
#include "Flamethrower.h"

FireBargeAI::FireBargeAI(glm::vec2 transform)
{
	parent = Enemy(Frame(50, //Enemy is 300px by 300px
#pragma region Frame Construction
		{
			{Blank(), Flamethrower(), Flamethrower(),Flamethrower(),Flamethrower(), Blank()},
			{Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower()},
			{Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower()},
			{Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower()},
			{Flamethrower(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Flamethrower()},
			{Blank(), Flamethrower(), Flamethrower(),Flamethrower(),Flamethrower(), Blank()}
		}
	#pragma endregion
	), 20, //Will tweak if it proves to be too much or too little
		this, transform);
	speed.y = -baseSpeed; //Tweak this number later

	//Fire Flamethrowers
	for (Weapon w : parent.GetFrame().GetWeapons())
	{
		w.Fire();
	}
}

FireBargeAI::~FireBargeAI()
{
}

void FireBargeAI::SecondaryFunction()
{
	if (parent.getPosition().y <= topLimit)
	{
		speed.y = 0;
		speed.x = -baseSpeed;
	}
	else if (parent.getPosition().y >= bottomLimit)
	{
		speed.y = 0;
		speed.x = baseSpeed;
	}
	else if (parent.getPosition().x <= leftLimit)
	{
		speed.y = baseSpeed;
		speed.x = 0;
	}
	else if (parent.getPosition().x >= rightLimit)
	{
		speed.y = -baseSpeed;
		speed.x = 0;
	}
}

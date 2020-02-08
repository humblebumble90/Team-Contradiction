#include "CannonBargeAI.h"
#include "Blank.h"
#include "BasicBody.h"

CannonBargeAI::CannonBargeAI(glm::vec2 transform)
{
	parent = Enemy(Frame(50, //Enemy is 300px by 300px
	#pragma region Frame Construction
		{
			{Blank(), Cannon(), Cannon(),Cannon(),Cannon(), Blank()},
			{Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon()},
			{Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon()},
			{Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon()},
			{Cannon(), BasicBody(), BasicBody(), BasicBody(), BasicBody(), Cannon()},
			{Blank(), Cannon(), Cannon(),Cannon(),Cannon(), Blank()}
		}
	#pragma endregion
	), 20, //Will tweak if it proves to be too much or too little
		this, transform);
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
		for (Weapon w : parent.GetFrame().GetWeapons())
		{
			w.Fire();
		}
	}
}

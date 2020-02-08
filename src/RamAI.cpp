#include "RamAI.h"
#include "BasicBody.h"

RamAI::RamAI(glm::vec2 transform)
{
	PlayerLockAI(Enemy(Frame(50, //Enemy is 50px by 50px
		{ {BasicBody()} }), 1, this, transform), 0.075f); //tweak that last number later
}

RamAI::~RamAI()
{
}

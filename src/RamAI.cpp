#include "RamAI.h"
#include "BasicBody.h"

RamAI::RamAI(glm::vec2 transform)
{
	PlayerLockAI(Enemy(Frame(30, //Enemy is 30px by 30px
		{ {BasicBody()} }), 1, this, transform), 0.075f); //tweak that last number later
}

RamAI::~RamAI()
{
}

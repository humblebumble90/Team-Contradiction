#include "RamAI.h"
#include "BasicBody.h"

RamAI::RamAI(float transform[2])
{
	PlayerLockAI(Enemy(Frame(30, //Enemy is 30px by 30px
		{ {BasicBody()} }), 1, this, transform), 0.075f); //tweak that last number later
}

RamAI::~RamAI()
{
}

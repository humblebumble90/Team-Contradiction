#include "AI.h"

AI::AI(){/*DANGER! Do not use!*/ }

AI::AI(Enemy parentRef)
{
	parent = parentRef;
}

AI::~AI(){}

void AI::PrimaryFunction()
{
	/*Leave this blank*/
}

float AI::GetSpeed(int i)
{
	if (i == 0 || i == 1)
		return speed[i];
	return NULL;
}

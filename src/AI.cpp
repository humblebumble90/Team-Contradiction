#include "AI.h"
#include "ShipComponent.h"

AI::AI(){/*DANGER! Do not use!*/ }

AI::~AI(){}

void AI::PrimaryFunction()
{
	/*Leave this blank*/
}

glm::vec2 AI::GetSpeed()
{
	return speed;
}

Enemy* AI::GetParent()
{
	return parent;
}

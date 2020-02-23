#include "BasicBody.h"
#include "Enemy.h"
#include "PlayerShip.h"
BasicBody::BasicBody()
{
	name = "BasicBody";
}
BasicBody::~BasicBody(){}

void BasicBody::Damage(int i)
{
		parent->getParent()->Damage(i);
}

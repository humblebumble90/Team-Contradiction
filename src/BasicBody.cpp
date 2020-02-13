#include "BasicBody.h"
#include "Enemy.h"
#include "PlayerShip.h"
BasicBody::BasicBody(){}
BasicBody::~BasicBody(){}

void BasicBody::Damage(int i)
{
		parent->getParent()->Damage(i);
}

#include "EnemyMissileAI.h"
#include "IndesBody.h"

EnemyMissileAI::EnemyMissileAI(float transform[2])
{
	PlayerLockAI(Enemy(Frame(6, //Enemy is 6px by 6 px
		{ {IndesBody(true)} }), 1, this, transform), 0.075f); //tweak that last number later
}

EnemyMissileAI::~EnemyMissileAI()
{
}

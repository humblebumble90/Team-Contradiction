#include "EnemyMissileAI.h"
#include "IndesBody.h"
#include "Game.h"

EnemyMissileAI::EnemyMissileAI(glm::vec2 transform)
{
	TheGame::Instance()->spawnEnemy(PlayerLockAI(Enemy(Frame(10, //Enemy is 10px by 10px
		{ {IndesBody(true)} }), 1, this, transform), 0.075f)); //tweak that last number later
}

EnemyMissileAI::~EnemyMissileAI()
{
}

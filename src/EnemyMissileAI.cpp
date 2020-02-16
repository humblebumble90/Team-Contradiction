#include "EnemyMissileAI.h"
#include "Game.h"
#include "Frame.h"
#include "IndesBody.h"

EnemyMissileAI::EnemyMissileAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build = { IndesBody(true) };
	TheGame::Instance()->spawnEnemy(PlayerLockAI(Enemy(Frame(10, //Enemy is 10px by 10px
		build, 1, 1), 1, this, transform), 0.075f)); //tweak that last number later
}

EnemyMissileAI::~EnemyMissileAI()
{
}

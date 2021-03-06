#include "EnemyMissileAI.h"
#include "Game.h"
#include "Frame.h"
#include "IndesBody.h"

EnemyMissileAI::EnemyMissileAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build = { IndesBody(true) };
	parent = new Enemy(new Frame(10, //Enemy is 10px by 10px
		build, 1, 1), 1, this, transform, "EnemyMissile");
	baseSpeed = 10.00f;
	Initialize();
}

EnemyMissileAI::EnemyMissileAI(glm::vec2 transform, glm::vec2 target)
{
	std::vector<ShipComponent> build = { IndesBody(true) };
	parent = new Enemy(new Frame(10, //Enemy is 10px by 10px
		build, 1, 1), 1, this, transform, "EnemyMissile");
	baseSpeed = 10.00f;
	Initialize(target);
}

EnemyMissileAI::~EnemyMissileAI()
{
}

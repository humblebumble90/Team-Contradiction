#include "EnemyCannonballAI.h"
#include "IndesBody.h"

EnemyCannonballAI::EnemyCannonballAI(glm::vec2 transform, glm::vec2 trajectory)
{
	std::vector<ShipComponent> build = { IndesBody(true) };
	parent = new Enemy(new Frame(25, //Enemy is 25px by 25px
		build, 1, 1), 1, this, transform, "EnemyCannonball");
	baseSpeed = 8.00f;
	Initialize(glm::vec2(GetParent()->getPosition().x+trajectory.x, GetParent()->getPosition().y + trajectory.y));
}

EnemyCannonballAI::~EnemyCannonballAI()
{
}

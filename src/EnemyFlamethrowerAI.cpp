#include "EnemyFlamethrowerAI.h"
#include "IndesBody.h"

EnemyFlamethrowerAI::EnemyFlamethrowerAI(glm::vec2 transform)
{

	std::vector<ShipComponent> build = { IndesBody(true) };
	parent = new Enemy(new Frame(25, build, 4, 1),1,this,transform,"EnemyFlamethrower");

	
}

EnemyFlamethrowerAI::~EnemyFlamethrowerAI() = default;


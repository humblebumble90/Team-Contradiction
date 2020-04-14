#include "EnemyFlamethrowerAI.h"
#include "IndesBody.h"

EnemyFlamethrowerAI::EnemyFlamethrowerAI(Flamethrower* ft)
{
	attachedWeapon = ft;
	if (ft->getID().x == 0) {
		transform = glm::vec2(-50, 0);
	}
	else if (ft->getID().y == 0) {
		transform = glm::vec2(0, -50);
		rotation = 90;
	}
	else {
		transform = glm::vec2(0, 50);
		rotation = 270;
	}
	std::vector<ShipComponent> build = { IndesBody(true), IndesBody(true), IndesBody(true), IndesBody(true) };
	parent = new Enemy(new Frame(25, build, 4, 1),1,this, ft->getPosition() + transform,"EnemyFlamethrower");
	
}

EnemyFlamethrowerAI::~EnemyFlamethrowerAI() = default;

void EnemyFlamethrowerAI::PrimaryFunction()
{
	parent->setPosition(attachedWeapon->getPosition() + transform);
}

int EnemyFlamethrowerAI::getRotation()
{
	return rotation;
}


#include "EnemyFlamethrowerAI.h"
#include "IndesBody.h"

EnemyFlamethrowerAI::EnemyFlamethrowerAI(Flamethrower* ft)
{
	attachedWeapon = ((Enemy*)ft->getParent()->getParent())->getAI();
	id = ft->getID().y + (ft->getID().x * ft->getParent()->GridHeight());
	if (ft->getID().x == 0) {
		transform = glm::vec2(-50, 0);
	}
	else if (ft->getID().y == 0) {
		transform = glm::vec2(0, -50);
		rotation = 90;
	}
	else if (ft->getID().y == ft->getParent()->GridHeight() - 1) {
		transform = glm::vec2(0, 50);
		rotation = 270;
	}
	else {
		transform = glm::vec2(0, -50);
		rotation = 180;
	}
	std::vector<ShipComponent> build = { IndesBody(true), IndesBody(true), IndesBody(true), IndesBody(true) };
	parent = new Enemy(new Frame(25, build, 4, 1),1,this, ft->getPosition() + transform,"EnemyFlamethrower");
	
}

EnemyFlamethrowerAI::~EnemyFlamethrowerAI() = default;

void EnemyFlamethrowerAI::PrimaryFunction()
{
	parent->setPosition(attachedWeapon->GetParent()->GetFrame()->GetBuild()[id].getPosition() + transform);
}

int EnemyFlamethrowerAI::getRotation()
{
	return rotation;
}


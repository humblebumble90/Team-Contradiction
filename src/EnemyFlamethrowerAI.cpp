#include "EnemyFlamethrowerAI.h"
#include "IndesBody.h"

EnemyFlamethrowerAI::EnemyFlamethrowerAI(Flamethrower* ft)
{
	attachedWeapon = ((Enemy*)ft->getParent()->getParent())->getAI();
	id = ft->getID().x + (ft->getID().y * ft->getParent()->GridWidth());
	std::cout << id << std::endl;
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
	if (((Enemy*)ft->getParent()->getParent())->getName() == "Deathcage") {
		if (ft->getID().y == 1) {
			setRotation(270);
		}
		if (ft->getID().y == 1) {
			setRotation(270);
		}
		else if (ft->getID().y == 16) {
			setRotation(90);
		}
		else {
			setRotation(0);
		}
	}
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

void EnemyFlamethrowerAI::setRotation(int i)
{
	rotation = i;
	switch (i) {
	case 0:
		transform = { -50, 0 };
		break;
	case 90:
		transform = { 0, -50 };
		break;
	case 180:
		transform = { 50, 0 };
		break;
	case 270:
		transform = { 0, 50 };
		break;
	}
}


#include "ShipComponent.h"
#include "CannonlordAI.h"
#include "ChaosAI.h"
#include "EnemyFlamethrowerAI.h"
ShipComponent::ShipComponent() = default;

ShipComponent::~ShipComponent()
{
}

glm::vec2 ShipComponent::getPosition()
{
	glm::vec2 parentPosition = parent->getParent()->getPosition();
	float offsetX = (iD.x - (parent->GridWidth() - 1) / 2) * parent->getGridSize(),
		  offsetY = (iD.y - (parent->GridHeight() - 1) / 2) * parent->getGridSize();
	float posX = parentPosition.x + offsetX,
		  posY = parentPosition.y + offsetY;
	if (parent->getParent()->getName() == "Cannonlord" || parent->getParent()->getName() == "Chaos" || parent->getParent()->getName() == "EnemyFlamethrower") {
		float angle;
		if (parent->getParent()->getName() == "Cannonlord") {
			angle = ((CannonlordAI*)((Enemy*)parent->getParent())->getAI())->getRotation()* M_PI / 180;
		}
		else if (parent->getParent()->getName() == "Chaos") {
			angle = ((ChaosAI*)((Enemy*)parent->getParent())->getAI())->getRotation()* M_PI / 180;
		}
		else if (parent->getParent()->getName() == "EnemyFlamethrower") {
			angle = ((EnemyFlamethrowerAI*)((Enemy*)parent->getParent())->getAI())->getRotation()* M_PI / 180;
		}
		return glm::vec2(
			cos(angle) * offsetX - sin(angle) * offsetY + parentPosition.x,
			sin(angle) * offsetX + cos(angle) * offsetY + parentPosition.y
		);
	}
	return glm::vec2(posX, posY);
}

void ShipComponent::setID(glm::vec2 id)
{
	if (iD.x == -1 && iD.y == -1)
	{
		iD = id;
	}
}

Frame* ShipComponent::getParent()
{
	return parent;
}

void ShipComponent::setParent(Frame* frame)
{
	parent = frame;
}

std::string ShipComponent::getName()
{
	return name;
}

glm::vec2 ShipComponent::getID()
{
	return iD;
}

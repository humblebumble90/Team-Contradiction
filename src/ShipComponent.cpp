#include "ShipComponent.h"
#include "CannonlordAI.h"
ShipComponent::ShipComponent() = default;

ShipComponent::~ShipComponent()
{
}

glm::vec2 ShipComponent::getPosition()
{
	glm::vec2 parentPosition = parent->getParent()->getPosition();
	float posX = parentPosition.x + ((iD.x - (parent->GridWidth() - 1) / 2) * parent->getGridSize()),
		  posY = parentPosition.y + ((iD.y - (parent->GridHeight() - 1) / 2) * parent->getGridSize());
	return parent->getParent()->getName() == "Cannonlord" ?
	#pragma region Position (Cannonlord)
		glm::vec2(
			2 * cos(posX - parentPosition.x) * (posX - parentPosition.x) * sin(0.5 * ((CannonlordAI*)((Enemy*)parent->getParent())->getAI())->getRotation()),
			2 * cos(posY - parentPosition.y) * (posY - parentPosition.y) * sin(0.5 * ((CannonlordAI*)((Enemy*)parent->getParent())->getAI())->getRotation())
		)
		/*
		Things I'll need for rotation:

		- The point i'm rotationg around			parentPosition
		- The point i'm at							posX & posY
		- The distance between me and the center	posX - parentPosition.x & posY - parentPosition.y (may need to abs)
		- The amount i'm rotating by				((CannonlordAI*)((Enemy*)parent->getParent())->getAI())->getRotation()
		*/
	#pragma endregion
	#pragma region Position (Normal)
		: glm::vec2(posX, posY);
	#pragma endregion
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

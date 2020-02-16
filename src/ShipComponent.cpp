#include "ShipComponent.h"
ShipComponent::ShipComponent() = default;

ShipComponent::~ShipComponent()
{
}

glm::vec2 ShipComponent::getPosition()
{
	glm::vec2 parentPosition = parent->getParent()->getPosition();
	return {
		parentPosition.x + ((iD.x - (parent->GridWidth() - 1) / 2) * parent->getGridSize()),
		parentPosition.y + ((iD.y - (parent->GridHeight() - 1) / 2) * parent->getGridSize())
	};
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

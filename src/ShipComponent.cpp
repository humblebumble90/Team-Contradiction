#include "ShipComponent.h"

ShipComponent::ShipComponent()
{
}

ShipComponent::~ShipComponent()
{
}

glm::vec2 ShipComponent::getPosition()
{
	glm::vec2 parentPosition = parent.GetParentType() == "Player" ? parent.GetPParent()->getPosition() : parent.GetEParent()->getPosition();
	return {
		parentPosition.x + ((iD.x - (parent.GridWidth() - 1) / 2) * parent.getGridSize()),
		parentPosition.y + ((iD.y - (parent.GridHeight() - 1) / 2) * parent.getGridSize())
	};
}

void ShipComponent::setID(int x, int y)
{
	if (iD == glm::vec2{ -1, -1 })
	{
		iD = { x, y };
	}
}

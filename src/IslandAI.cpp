#include "IslandAI.h"
#include "IndesBody.h"

IslandAI::IslandAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		IndesBody(false), IndesBody(false), IndesBody(false)
	};
#pragma endregion
	parent = new Enemy(new Frame(240, //Enemy is 75px by 75px
		build, 3, 1), 999, this, transform, "Island");
	speed.x = -5.00f; //Tweak this number later
	score = 0;
}

IslandAI::~IslandAI()
{
}

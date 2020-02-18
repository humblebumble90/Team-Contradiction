#include "RamAI.h"
#include "Game.h"
#include "Frame.h"
#include "BasicBody.h"

RamAI::RamAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build = { BasicBody() };
	TheGame::Instance()->spawnEnemy(new PlayerLockAI(new Enemy(new Frame(50, //Enemy is 50px by 50px
		build, 1, 1), 1, this, transform, "Ram"), 0.075f)); //tweak that last number later
}

RamAI::~RamAI()
{
}

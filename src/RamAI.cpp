#include "RamAI.h"
#include "Game.h"
#include "Frame.h"
#include "BasicBody.h"

RamAI::RamAI(glm::vec2 transform)
{
	TheGame::Instance()->spawnEnemy(PlayerLockAI(Enemy(Frame(50, //Enemy is 50px by 50px
		{BasicBody()}, 1, 1), 1, this, transform), 0.075f)); //tweak that last number later
}

RamAI::~RamAI()
{
}

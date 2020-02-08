#include "LevelScene.h"
#include "RamAI.h"
#include "ZigzagAI.h"

LevelScene::LevelScene()
{
}

LevelScene::~LevelScene()
{
}

void LevelScene::update()
{
	++time;
	#pragma region Spawn Enemies
	if (time == ramSpawnTimer[ramIteration])
	{
		enemies.push_back(new RamAI(ramSpawnLocation[ramIteration]));
		++ramIteration;
	}
	if (time == zigzagSpawnTimer[zigzagIteration])
	{
		enemies.push_back(new ZigzagAI(zigzagSpawnLocation[zigzagIteration]));
		++zigzagIteration;
	}
	#pragma endregion
}
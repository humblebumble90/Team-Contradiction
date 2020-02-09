#include "LevelScene.h"
#include "RamAI.h"
#include "ZigzagAI.h"
#include "Game.h"

LevelScene::LevelScene()
{
}

LevelScene::~LevelScene()
{
}

void LevelScene::update()
{
	++time;
	CollisionManager::squaredRadiusCheck(player, enemy);
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

void LevelScene::DestroyEnemy(Enemy* enemy)
{
	for (int i = 0; i < enemies.size(); ++i) {
		if (/*enemies[i]->GetParent().getPosition() == enemy->getPosition() && */enemies[i]->GetParent().GetFrame().GetEParent() == enemy) {
			enemies.erase(enemies.begin()+(i-1));
			break;
		}
	}
}

void LevelScene::GameOver()
{
	TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
}

glm::vec2 LevelScene::getPlayerPosition()
{
	return player->getPosition();
}

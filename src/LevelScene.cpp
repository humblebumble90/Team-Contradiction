#include "LevelScene.h"
#include "RamAI.h"
#include "ZigzagAI.h"
#include "BasicBody.h"
#include "IndesBody.h"
#include "CollisionManager.h"

LevelScene::LevelScene()
{
}

LevelScene::~LevelScene()
{
	
}

void LevelScene::update()
{
	++time;
	std::cout << "Time: " << time << std::endl;
#pragma region Player Collision and invinciblity
	if (!(player->getInvincibility()))
	{
		//for (Enemy* enemy : m_pEnemy)
		//{
		//	CollisionManager::squaredRadiusCheck(player, enemy);
		//}
		if (typeid(playerComponent) == typeid(BasicBody)
			&& typeid(enemyComponent) == typeid(BasicBody) || typeid(enemyComponent) == typeid(IndesBody))
		{
			CollisionManager::shipComponentCheck(playerComponent, enemyComponent);
		}
	}
	if (CollisionManager::shipComponentCheck(playerComponent, enemyComponent) == true)
	{
		player->Damage(1);
	}
#pragma endregion
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
		if (/*enemies[i]->GetParent().getPosition() == enemy->getPosition() && */enemies[i]->GetParent().GetFrame().getParent() == enemy) {
			enemies.erase(enemies.begin()+(i-1));
			break;
		}
	}
}

void LevelScene::GameOver()
{
}

glm::vec2 LevelScene::getPlayerPosition()
{
	return ((GameObject*)player)->getPosition();
}

void LevelScene::spawnEnemy(AI enemyAI)
{
	enemies.push_back(&enemyAI);
}

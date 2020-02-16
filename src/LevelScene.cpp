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
	player->update();
	m_pMap->update();
	std::cout << "updating..." << std::endl;
#pragma region Player Collision and invinciblity
	if (!(player->getInvincibility()))
	{
		//for (Enemy* enemy : m_pEnemy)
		//{
		//	CollisionManager::squaredRadiusCheck(player, enemy);
		//}

		for (ShipComponent s : player->GetFrame().GetBuild())
		{
			if (typeid(s) == typeid(BasicBody))
			{
				for (AI* a : enemies)
				{
					for (ShipComponent c : a->GetParent().GetFrame().GetBuild())
					{
						if (typeid(c) == typeid(BasicBody) || typeid(c) == typeid(IndesBody))
						{
							if (CollisionManager::shipComponentCheck(s, c))
							{
								((BasicBody&)s).Damage(1);

								if (typeid(c) == typeid(BasicBody))
								{
									((BasicBody&)c).Damage(1);
								}
								else
								{
									((IndesBody&)c).Damage(s);
								}
							}

						}
					}
				}
			}
		}
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
	for(AI* e: enemies)
	{
		e->GetParent().draw();
	}
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

PlayerShip* LevelScene::getPlayerShip()
{
	return player;
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

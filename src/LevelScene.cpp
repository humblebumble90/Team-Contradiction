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
	spawnedEnemy = false;
	player->update();
	m_pMap->update();
	for (AI* a : enemies) {
		a->GetParent()->update();
	}
	for (DisplayObject* d : playerWeapons) {
		d->update();
	}
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
					for (ShipComponent c : a->GetParent()->GetFrame()->GetBuild())
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
		spawnEnemy(new RamAI(ramSpawnLocation[ramIteration]));
		++ramIteration;
	}
	if (time == zigzagSpawnTimer[zigzagIteration])
	{
		spawnEnemy(new ZigzagAI(zigzagSpawnLocation[zigzagIteration]));
		++zigzagIteration;
	}
	#pragma endregion
}

void LevelScene::draw()
{
	m_pMap->draw();
	player->draw();
	for (AI* a : enemies) {
		a->GetParent()->draw();
	}
	for (DisplayObject* d : playerWeapons) {
		d->draw();
	}
}

void LevelScene::DestroyEnemy(Enemy* enemy)
{
	for (int i = 0; i < enemies.size(); ++i) {
		if (/*enemies[i]->GetParent().getPosition() == enemy->getPosition() && */enemies[i]->GetParent()->GetFrame()->getParent() == enemy) {
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

void LevelScene::spawnEnemy(AI* enemyAI)
{
	if (spawnedEnemy == false) {
		spawnedEnemy = true;
		enemies.push_back(enemyAI);
	}
}

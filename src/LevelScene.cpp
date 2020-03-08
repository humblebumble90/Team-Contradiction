#include "LevelScene.h"
#include "RamAI.h"
#include "ZigzagAI.h"
#include "CannoneerAI.h"
#include "GuardianAI.h"
#include "DiagonAI.h"
#include "BlastAI.h"
#include "BasicBody.h"
#include "IndesBody.h"
#include "CollisionManager.h"
#include <experimental/coroutine>

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
	if(player->getPlayerLives() >= 0)
	{
		player->update();
	}
	m_pLivesLabel->setText("Lives: " + std::to_string(player->getPlayerLives()));
	m_pMap->update();
	for (int z = 0; z < enemies.size(); ++z) {
		enemies[z]->GetParent()->update();
	}
	for (PlayerWeapon* pw : playerWeapons) {
		pw->update();
	}
	/*
	#pragma region Player Collision and invinciblity
	if (player->getInvincibility() == false && enemies.empty() == false)
	{
		//for (Enemy* enemy : m_pEnemy)
		//{
		//	CollisionManager::squaredRadiusCheck(player, enemy);
		//}
		//get the player's build
		for (ShipComponent s : player->GetFrame()->GetBuild())
		{
			//if the build is a basicbody
			if (s.getName() == "BasicBody")
			{
				// for all enemies
				//std::cout << s.getPosition().x << std::endl;
				for (AI* a : enemies)
				{
					//get the ship component of the enemies
					for (ShipComponent c : a->GetParent()->GetFrame()->GetBuild())
					{
						//if the names are basic body and indesbody
						if (c.getName() == "BasicBody" || c.getName() == "IndesBody")
						{
							//std::cout << s.getName() << std::endl;
							//std::cout << s.getPosition().x << std::endl;
							//std::cout << s.getPosition().y << std::endl;
							//std::cout << c.getName() << std::endl;
							//std::cout << c.getPosition().x << std::endl;
							//std::cout << c.getPosition().y << std::endl;
							//and they are colliding then do this
							if (CollisionManager::shipComponentCheck(s, c))
							{
								std::cout << "something" << std::endl;
								player->Damage(1);

								if (c.getName() == "BasicBody")
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
	#pragma region Player Weapon Collision
	for (int b = 0; b < playerWeapons.size(); ++ b) {
		for (ShipComponent s : playerWeapons[b]->getFrame()->GetBuild())
		{
			if (s.getName() == "BasicBody" || s.getName() == "IndesBody")
			{
				for (AI* a : enemies)
				{
					for (ShipComponent c : a->GetParent()->GetFrame()->GetBuild())
					{
						if (c.getName() == "BasicBody" || c.getName() == "IndesBody")
						{
							if (CollisionManager::shipComponentCheck(s, c))
							{
								if (s.getName() == "BasicBody")
								{
									((BasicBody&)s).Damage(1);
								}
								else
								{
									((IndesBody&)s).Damage(c);
								}
							}

						}
					}
				}
			}
		}
	}
#pragma endregion
	*/
	#pragma region Collisions
	if (enemies.size() > 0 && (playerWeapons.size() > 0 || !player->getInvincibility())) {
		for (AI* enemy : enemies) {
			for (ShipComponent es : enemy->GetParent()->GetFrame()->GetBuild()) {
				if (es.getName() == "BasicBody" || es.getName() == "IndesBody") {
					if (playerWeapons.size() > 0) {
						for (PlayerWeapon* pw : playerWeapons) {
							for (ShipComponent ps : pw->getFrame()->GetBuild()) {
								if (ps.getName() == "BasicBody" || ps.getName() == "IndesBody") {
									if (CollisionManager::shipComponentCheck(es, ps))
									{
										ShipComponent temp[2] = { ps, es };
										Damage(temp);
									}
								}
							}
						}
					}
					if (!player->getInvincibility()) {
						for (ShipComponent ps : player->GetFrame()->GetBuild()) {
							if (ps.getName() == "BasicBody" || ps.getName() == "IndesBody") {
								if (CollisionManager::shipComponentCheck(es, ps))
								{
									ShipComponent temp[2] = { ps, es };
									Damage(temp);
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
	if (ramIteration < ramSpawnTimer.size()) {
		if (time == ramSpawnTimer[ramIteration])
		{
			spawnEnemy(new RamAI(ramSpawnLocation[ramIteration]));
			++ramIteration;
		}
	}
	if (zigzagIteration < zigzagSpawnTimer.size()) {
		if (time == zigzagSpawnTimer[zigzagIteration])
		{
			spawnEnemy(new ZigzagAI(zigzagSpawnLocation[zigzagIteration]));
			++zigzagIteration;
		}
	}
	if (cannoneerIteration < cannoneerSpawnTimer.size()) {
		if (time == cannoneerSpawnTimer[cannoneerIteration])
		{
			spawnEnemy(new CannoneerAI(cannoneerSpawnLocation[cannoneerIteration]));
			++cannoneerIteration;
		}
	}
	if (guardianIteration < guardianSpawnTimer.size()) {
		if (time == guardianSpawnTimer[guardianIteration])
		{
			spawnEnemy(new GuardianAI(guardianSpawnLocation[guardianIteration]));
			++guardianIteration;
		}
	}
	if (diagonIteration < diagonSpawnTimer.size()) {
		if (time == diagonSpawnTimer[diagonIteration])
		{
			spawnEnemy(new DiagonAI(diagonSpawnLocation[diagonIteration]));
			++diagonIteration;
		}
	}
	if (blastIteration < blastSpawnTimer.size()) {
		if (time == blastSpawnTimer[blastIteration])
		{
			spawnEnemy(new BlastAI(blastSpawnLocation[blastIteration]));
			++blastIteration;
		}
	}
	#pragma endregion
}

void LevelScene::draw()
{
	m_pMap->draw();
	if (player->getPlayerLives() >= 0)
	{
		player->draw();
	}
	m_pLivesLabel->draw();
	for (PlayerWeapon* pw : playerWeapons) {
		pw->draw();
	}
	for (AI* a : enemies) {
		a->GetParent()->draw();
	}
}

void LevelScene::DestroyEnemy(Enemy* enemy)
{
	for (int i = 0; i < enemies.size(); ++i) {
		if (/*enemies[i]->GetParent().getPosition() == enemy->getPosition() && */enemies[i]->GetParent()->GetFrame()->getParent() == enemy) {
			enemies.erase(enemies.begin()+i);
			break;
		}
	}
}
void LevelScene::DestroyWeapon(PlayerWeapon* weapon)
{
	for (int i = 0; i < playerWeapons.size(); ++i) {
		if (playerWeapons[i]->getFrame()->getParent() == weapon) {
			playerWeapons.erase(playerWeapons.begin() + i);
			break;
		}
	}
}

PlayerShip* LevelScene::getPlayerShip()
{
	return player;
}

void LevelScene::Damage(ShipComponent sc[2])
{
	for (int z = 0; z < 2; ++z) {
		if (sc[z].getName() == "BasicBody") {
			int i = sc[1 - z].getParent()->getParent()->getName() == "Cannon" ? 2 : 1;
			((BasicBody&)sc[z]).Damage(i);
		}
		else if (sc[z].getName() == "IndesBody") {
			((IndesBody&)sc[z]).Damage(sc[1 - z]);
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

void LevelScene::spawnEnemy(AI* enemyAI)
{
	if (spawnedEnemy == false) {
		if (!enemyAI->GetParent()->getName().find("Barge")) {
			spawnedEnemy = true;
		}
		enemies.push_back(enemyAI);
	}
}

void LevelScene::spawnPlayerWeapon(PlayerWeapon* playerWeapon)
{
	playerWeapons.push_back(playerWeapon);
}

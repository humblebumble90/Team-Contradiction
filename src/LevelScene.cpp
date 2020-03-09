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
	spawnedEnemy = false;
	initializeLabels();
	if (player->getPlayerLives() >= 0)
	{
		player->update();
	}
	if (m_pSpeedLabel != nullptr){
		m_pSpeedLabel->setText("Speed: " + std::to_string(player->getPlayerSpeed()));
	}
	if (m_pLivesLabel != nullptr)
	{
		m_pLivesLabel->setText("Lives: " + std::to_string(player->getPlayerLives()));
	}
	if (m_pMap != nullptr)
	{
		m_pMap->update();
	}
	if (m_pMap2 != nullptr)
	{
		m_pMap2->update();
	}
	for (int z = 0; z < enemies.size(); ++z) {
		enemies[z]->GetParent()->update();
	}
	for (PlayerWeapon* pw : playerWeapons) {
		pw->update();
	}
	#pragma region Collisions
	//if the enemies are spawned or if the player is invincible
	if (enemies.size() > 0 && (playerWeapons.size() > 0 || !player->getInvincibility())) {
		for (AI* enemy : enemies) {
			for (ShipComponent es : enemy->GetParent()->GetFrame()->GetBuild()) {
				if (es.getName() == "BasicBody" || es.getName() == "IndesBody") {
					if (playerWeapons.size() > 0) {
						for (PlayerWeapon* pw : playerWeapons) {
							for (ShipComponent ps : pw->getFrame()->GetBuild()) {
								if (ps.getName() == "BasicBody" || ps.getName() == "IndesBody") {
									if(ps.getName() == "IndesBody" && es.getName() == "BasicBody"
										&& CollisionManager::shipComponentCheck(ps,es))
									{
										player->setKillCounter(1);
										if (player->getKillCounter() == 20)
										{
											m_pshield = new Shield();
											shieldSpawnPos = es.getParent()->getParent()->getPosition();
											m_pshield->setPosition(shieldSpawnPos);
										}
									}
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
	if(m_pshield != nullptr && CollisionManager::squaredRadiusCheck(player, m_pshield))
	{
		player->setShieldAvailable(true);
		m_pshield->setCollided(true);
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

	if(player->getPlayerLives() == 0 && !player->getShieldAvailable())
	{
		Game::Instance()->changeSceneState(END_SCENE);
	}


}

void LevelScene::draw()
{
	if (m_pMap != nullptr)
	{
		m_pMap->draw();
	}
	if (m_pMap2 != nullptr)
	{
		m_pMap2->draw();
	}
	if (player->getPlayerLives() >= 0)
	{
		player->draw();
	}
	if (m_pSpeedLabel != nullptr) {
		m_pSpeedLabel->draw();
	}
	if (m_pLivesLabel != nullptr) {
		m_pLivesLabel->draw();
	}

	for (PlayerWeapon* pw : playerWeapons) {
		pw->draw();
	}
	for (AI* a : enemies) {
		a->GetParent()->draw();
	}
	if (m_pControl_Img != nullptr)
	{
		m_pControl_Img->draw();
	}
	if(m_pshield != nullptr && !m_pshield->getCollided())
	{
		m_pshield->draw();
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

void LevelScene::initializeLabels()
{
	if (player != nullptr && m_pLivesLabel == nullptr && m_pSpeedLabel == nullptr)
	{
		std::cout << "Working checker...\n";
		SDL_Color yellow = { 255, 255, 0, 255 };
		m_pLivesLabel = new Label("Lives: " + std::to_string(player->getPlayerLives()), "Consolas",
			24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.45f, 10.0f), TTF_STYLE_NORMAL, false);
		m_pSpeedLabel = new Label("Speed: " + std::to_string(player->getPlayerSpeed()), "Consolas",
			24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.65f, 10.0f), TTF_STYLE_NORMAL, false);
		return;
	}
}



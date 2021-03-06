#include "LevelScene.h"
#include "RamAI.h"
#include "ZigzagAI.h"
#include "CannoneerAI.h"
#include "GuardianAI.h"
#include "DiagonAI.h"
#include "BlastAI.h"
#include "IslandAI.h"
#include "BasicBody.h"
#include "IndesBody.h"
#include "CollisionManager.h"
#include <experimental/coroutine>
#include "Game.h"
#include "FlyOntoScreenAI.h"
#include "Scoreboard.h"
#include "ExplosionManager.h"

LevelScene::LevelScene()
{

}

LevelScene::~LevelScene()
{
	
}

void LevelScene::checkShieldCollision()
{
	if (!m_pshields.empty())
	{
		for (int i = 0; i < m_pshields.size(); i++)
		{
			auto item = m_pshields[i];
			if (CollisionManager::squaredRadiusCheck(player, item)
				|| item->getPosition().x < -5.0f)
			{
				player->setShieldAvailable(true);
				//item->setCollided(true);
				m_pshields[i]->clean();
				m_pshields.erase(m_pshields.begin() + i);
				m_pshields.shrink_to_fit();
				break;
			}
			if (TheTextureManager::Instance()->getTexture(item->getID()) != nullptr)
			{
				item->update();
			}
		}
	}
}

void LevelScene::checkWeaponCollision()
{
	for (int i = 0; i < m_pWeapons.size(); ++i)
	{
		if (CollisionManager::squaredRadiusCheck(player, m_pWeapons[i]))
		{
			PlayerWeaponType weaponType = m_pWeapons[i]->getWeaponType();
			player->changeWeapon(weaponType);
			m_pWeapons[i]->clean();
			m_pWeapons.erase(m_pWeapons.begin() + i);
			m_pWeapons.shrink_to_fit();
		}
	}
}

void LevelScene::update()
{
	if (Scoreboard::Instance()->getScore() == 0 && Scoreboard::Instance()->getHighScore() > 0) {
		Scoreboard::Instance()->setScore(Scoreboard::Instance()->getHighScore());
		player->playerScore = Scoreboard::Instance()->getHighScore();
		player->playerHighScore = Scoreboard::Instance()->getHighScore();
	}
	if (bossDown) {
		TheGame::Instance()->changeSceneState(nextScene);
	}
	else {
		if (!player->getPlayerDead())
		{
			++time;
			spawnedEnemy = false;
			if (!initialized)
			{
				initialize();
			}
			if (player->getPlayerLives() >= 0)
			{
				player->update();
			}
			if (m_pMap != nullptr)
			{
				m_pMap->update();
			}
			if (m_pMap2 != nullptr)
			{
				m_pMap2->update();
			}
			if (player->getShieldAvailable() && player->getPlayerLives() == 0)
			{
				mpShield_aurora->update();
			}
			for (int z = 0; z < enemies.size(); ++z) {
				enemies[z]->GetParent()->update();
			}
			for (PlayerWeapon* pw : playerWeapons)
			{
				pw->update();
			}
#pragma region Collisions
			//if the enemies are spawned or if the player is not invincible
			if (!playerWeapons.empty() || !player->getInvincibility()) {
				for (AI* enemy : enemies) {
					if (!playerWeapons.empty()) {
						for (PlayerWeapon* pw : playerWeapons) {
							collisionCheck(((FlyOntoScreenAI*)enemy)->isBoss, enemy, pw);
						}
					}
					if (!player->getInvincibility()) {
						collisionCheck(((FlyOntoScreenAI*)enemy)->isBoss, enemy);
					}
				}
			}
			if (!m_pshields.empty())
			{
				checkShieldCollision();
			}
			for (int i = 0; i < m_pWeapons.size(); ++i)
			{
				m_pWeapons[i]->update();
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
			if (islandIteration < islandSpawnTimer.size()) {
				if (time == islandSpawnTimer[islandIteration])
				{
					spawnEnemy(new IslandAI(islandSpawnLocation[islandIteration]));
					++islandIteration;
				}
			}
#pragma endregion

			if (player->getPlayerLives() < 0)
			{
				player->setPlayerDead(true);
				if (TheGame::Instance()->Continue() < 1)
				{
					TheGame::Instance()->changeSceneState(END_SCENE);
				}
			}
		}
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

	for (int i = 0; i < m_pWeapons.size(); ++i)
	{
		m_pWeapons[i]->draw();
	}
	
	for (PlayerWeapon* pw : playerWeapons) {
		pw->draw();
	}
	for (AI* a : enemies) {
		a->GetParent()->draw();
	}
	if(!m_pshields.empty())
	{
		for(auto item : m_pshields)
		{
			if(TheTextureManager::Instance()->getTexture(item->getID()) != nullptr)
			{
				item->draw();
			}
		}
	}
	checkWeaponCollision();

	if(player->getShieldAvailable() && player->getPlayerLives() == 0)
	{
		mpShield_aurora->draw();
	}
	ExplosionManager::Instance()->draw();

	if (initialized)
	{
		m_pLivesLabel->draw();
		m_pScoreLabel->draw();
		m_pHighScoreLabel->draw();
		m_pNumOfContinueLabel->draw();
	}
	if (player->getPlayerLives() >= 0)
	{
		player->draw();
	}

	if (m_pControl_Img != nullptr)
	{
		m_pControl_Img->draw();
	}
	if (player->getPlayerDead() && TheGame::Instance()->Continue() > 0)
	{
		m_pContinueLabel1->draw();
		m_pContinueLabel2->draw();
	}
}

void LevelScene::DestroyEnemy(Enemy* enemy)
{
	if(((FlyOntoScreenAI*)enemy)->isBoss)
	{
		for (int i = 0; i < enemies.size(); ++i) {
			if (/*enemies[i]->GetParent().getPosition() == enemy->getPosition() && */enemies[i]->GetParent()->GetFrame()->getParent() == enemy) {
				//SpawnExplosion(enemies[i]->GetParent()->getPosition());
				enemies.erase(enemies.begin() + i);
				break;
			}
		}
		player->setBossKillCounter(1);
	}
	else
	{
		for (int i = 0; i < enemies.size(); ++i) {
			if (/*enemies[i]->GetParent().getPosition() == enemy->getPosition() && */enemies[i]->GetParent()->GetFrame()->getParent() == enemy) {
				//SpawnExplosion(enemies[i]->GetParent()->getPosition());
				enemies.erase(enemies.begin() + i);
				break;
			}
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

void LevelScene::SpawnExplosion(glm::vec2 position)
{
	playSound("Explosion", 0);
	player->setKillCounter(1);
	updateLabels();
	//idNum++;
	////std::cout << "Exp Num: "<< idNum << std::endl;
	//expID = "exp " + std::to_string(idNum);
	//Explosion* exp = new Explosion(expID);
	//addChild(exp);
	//exp->setPosition(position);
	//m_pExplosions.push_back(exp);
	//DestroyExplosion();
	auto explosion = ExplosionManager::Instance()->getExplosion();

	explosion->setPosition(position);
	explosion->activate();
	//std::cout << "Explosion position X: " << explosion->getPosition().x << "\n Explosion position Y: "
	//	<< explosion->getPosition().y << "\n activated: " << explosion->getIsActive() << std::endl;
}

PlayerShip* LevelScene::getPlayerShip()
{
	return player;
}

void LevelScene::updateLabels()
{
	m_pLivesLabel->setText("Lives: " + std::to_string(player->getPlayerLives()));
	m_pScoreLabel->setText("Score: " + std::to_string(Scoreboard::Instance()->getScore()));
	m_pHighScoreLabel->setText("HighScore: " + std::to_string(Scoreboard::Instance()->getHighScore()));
	m_pNumOfContinueLabel->setText("Continue: " + std::to_string(TheGame::Instance()->Continue()));
}

void LevelScene::spawnShield(AI* enemy)
{
	player->initializeKillCounter();
	shieldID = "Shield" + std::to_string(idNum);
	//std::cout << "Shield ID: "<< shieldID << std::endl;
	Shield* shield = new Shield(shieldID);
	shieldSpawnPos = enemy->GetParent()->getPosition();
	shield->setPosition(shieldSpawnPos);
	shield->setVelocity
		(glm::vec2(-5.0f, 0.0f));
	addChild(shield);
	m_pshields.push_back(shield);
	//std::cout << "Shield gen\n";
}

void LevelScene::collisionCheck(bool boss, AI* enemy, PlayerWeapon* pw)
{
	//Collision check for Enemies versus Player Weapon
	if (boss &&
 CollisionManager::squaredRadiusCheck(pw,enemy->GetParent()) &&
		enemy->GetParent()->getHitTimer() <= 0) {
		for (ShipComponent es : enemy->GetParent()->GetFrame()->GetBuild()) {
			if (es.getName() == "BasicBody") {
				for (ShipComponent ps : pw->getFrame()->GetBuild()) {
					if (ps.getName() == "IndesBody") {
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
	else {
		if (CollisionManager::squaredRadiusCheck(enemy->GetParent(), pw) && enemy->GetParent()->getType() != ENEMY_WEAPON)
		{
			enemy->GetParent()->Damage(1);
			//std::cout << "Enemy name: " <<enemy->GetParent()->getName()<<
				//"\nenemy health: (should be 0)"<<enemy->GetParent()->getHealth() << std::endl;
			pw->Damage(1);
			//Temporary calling score method for testing.
			//player->addScore(/*some amount for score(integer)*/);
			//player->setKillCounter(1);
			//player->addScore(player->getKillCounter());
		}
		if (player->getKillCounter() > 0 &&
			player->getKillCounter() % 20 == 0)
		{
			spawnShield(enemy);			
		}
	}
}

void LevelScene::collisionCheck(bool boss, AI* enemy)
{
	//Collision Check used for enemies versus player
	if (boss)
	{
		for (ShipComponent es : enemy->GetParent()->GetFrame()->GetBuild()) {
			if (es.getName() == "BasicBody" || es.getName() == "IndesBody") {
				for (ShipComponent ps : player->GetFrame()->GetBuild()) {
					if (ps.getName() == "BasicBody") {
						if (CollisionManager::shipComponentCheck(es, ps))
						{
							ShipComponent temp[2] = { ps, es };
							Damage(temp);
							updateLabels();
						}
					}
				}
			}
		}
	}
	else {
		if (CollisionManager::squaredRadiusCheck(enemy->GetParent(), player))
		{
			if(!player->getInvincibility())
			{
				player->Damage(1);
				SpawnExplosion(player->getPosition());
				updateLabels();
			}
		}
	}
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
	//if (sc[0].getName() == "IndesBody" && sc[1].getName() == "BasicBody")
	//{
	//	if(!(((FlyOntoScreenAI*)((Enemy*)sc[1].getParent()->getParent())->getAI())->isBoss))
	//	{
	//		player->setKillCounter(1);
	//		player->addScore(1);//Temporary calling score method for testing.
	//		//player->addScore(/*some amount for score(integer)*/);
	//		m_pScoreLabel->setText("Score: " + std::to_string(Scoreboard::Instance()->getScore()));
	//		m_pHighScoreLabel->setText("HighScore: " + std::to_string(Scoreboard::Instance()->getHighScore()));
	//		
	//		
	//	}
	//	if (player->getKillCounter() > 0 &&
	//		player->getKillCounter() % 20 == 0)
	//	{
	//		spawnShield(sc);			
	//	}
	//}
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

void LevelScene::initialize()
{
	//std::cout << "Initialized.\n";
	SDL_Color yellow = { 255, 255, 255, 255 };
	//Labels
	m_pScoreLabel = new Label("Score: " + std::to_string(Scoreboard::Instance()->getScore()), "TimesNewRoman",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.15f, 10.0f), TTF_STYLE_NORMAL, true);
	m_pHighScoreLabel = new Label("High Score: " + std::to_string(Scoreboard::Instance()->getHighScore()), "TimesNewRoman",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.40f, 10.0f), TTF_STYLE_NORMAL, true);
	m_pLivesLabel = new Label("Lives: " + std::to_string(Scoreboard::Instance()->getLives()), "TimesNewRoman",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.65f, 10.0f), TTF_STYLE_NORMAL, true);
	m_pNumOfContinueLabel = new Label("Continue: " + std::to_string(TheGame::Instance()->Continue()), "TimesNewRoman",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.90f, 10.0f), TTF_STYLE_NORMAL, true);
	/*m_pSpeedLabel = new Label("Speed: " + std::to_string(player->getPlayerSpeed()), "TimesNewRoman",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.65f, 10.0f), TTF_STYLE_NORMAL, false);*/
	m_pContinueLabel1 = new Label("Push space bar to continue",
		"TimesNewRoman", 40, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.50f),
		TTF_STYLE_NORMAL,true);
	m_pContinueLabel2 = new Label("Or push R to restart the game",
		"TimesNewRoman", 40, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.60f),
		TTF_STYLE_NORMAL, true);
	mpShield_aurora = new Shield_Aurora();
	addChild(mpShield_aurora);
	m_pWeapons.push_back(new Power_Up(MISSILE_LAUNCHER));
	m_pWeapons.push_back(new Power_Up(CANNON));
	m_pWeapons[1]->setPosition(glm::vec2(Config::SCREEN_WIDTH + 50, Config::SCREEN_HEIGHT * 0.3));
	m_pWeapons[0]->setPosition(glm::vec2(Config::SCREEN_WIDTH + 50, Config::SCREEN_HEIGHT * 0.7));
	initialized = true;
}





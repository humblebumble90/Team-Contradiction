#pragma once
#ifndef __LEVELSCENE__
#define __LEVELSCENE__

#include "PlayerShip.h"
#include "WeaponMissile.h"
#include "AI.h"
#include "Map.h"
#include "Label.h"
#include <SDL_ttf.h>
#include "Control_Img.h"
#include "Shield.h"
#include "Power_Up.h"
#include "explosion.h"
#include "Shield_Aurora.h"

class LevelScene : public Scene
{
public:
	LevelScene();
	virtual ~LevelScene();
	void update() override;
	void draw() override;
	void DestroyEnemy(Enemy* enemy);
	void DestroyWeapon(PlayerWeapon* weapon);
	void SpawnExplosion(glm::vec2 position);
	void GameOver();
	glm::vec2 getPlayerPosition();
	void spawnEnemy(AI* enemyAI);
	void spawnPlayerWeapon(PlayerWeapon* playerWeapon);
	PlayerShip* getPlayerShip();
	void updateLabels();

	bool bossDown = false;

protected:
	bool scrolling = true, spawnedEnemy=false;
	#pragma region Game Objects
	std::vector<AI*> enemies;
	PlayerShip* player;
	//Label* m_pSpeedLabel;
	Label* m_pLivesLabel;
	Label* m_pScoreLabel;
	Label* m_pHighScoreLabel;
	Label* m_pContinueLabel1;
	Label* m_pContinueLabel2;
	Label* m_pNumOfContinueLabel;

	Control_Img* m_pControl_Img = new Control_Img();
	std::vector<PlayerWeapon*> playerWeapons;
	std::vector<Shield*> m_pshields;
	std::vector<Power_Up*> power_ups;
	glm::vec2 shieldSpawnPos;

	Map* m_pMap;
	Map* m_pMap2;
	Shield_Aurora* mpShield_aurora;
	#pragma endregion
	#pragma region Spawn Timers
	int time = 0, ramIteration = 0, zigzagIteration = 0, cannoneerIteration = 0, guardianIteration = 0, diagonIteration = 0, blastIteration = 0, islandIteration = 0;
	std::vector<int> ramSpawnTimer, zigzagSpawnTimer, cannoneerSpawnTimer, guardianSpawnTimer, diagonSpawnTimer, blastSpawnTimer, islandSpawnTimer;
	std::vector<glm::vec2> ramSpawnLocation, zigzagSpawnLocation, cannoneerSpawnLocation, guardianSpawnLocation, diagonSpawnLocation, blastSpawnLocation, islandSpawnLocation;
	#pragma endregion

	int level;
	SceneState nextScene;
private:
	void Damage(ShipComponent sc[2]);
	void checkShieldCollision();
	void spawnShield(AI* enemy);
	void collisionCheck(bool boss, AI* enemy, PlayerWeapon* pw);
	void collisionCheck(bool boss, AI* enemy);
	void initialize();
	int idNum = 0;
	std::string shieldID;
	bool initialized;
};
#endif
#pragma once
#ifndef __LEVELSCENE__
#define __LEVELSCENE__

#include "PlayerShip.h"
#include "WeaponMissile.h"
#include "AI.h"
#include "Map.h"

class LevelScene : public Scene
{
public:
	LevelScene();
	virtual ~LevelScene();
	void update() override;
	void DestroyEnemy(Enemy* enemy);
	void GameOver();
	glm::vec2 getPlayerPosition();
	void spawnEnemy(AI enemyAI);
	PlayerShip* getPlayerShip();
protected:
	bool scrolling = true;
	#pragma region Game Objects
	std::vector<AI*> enemies;
	PlayerShip* player;
	std::vector<WeaponMissile*> playerWeapons;

	Map* m_pMap;
	#pragma endregion
	#pragma region Spawn Timers
	int time = 0, ramIteration = 0, zigzagIteration = 0;
	std::vector<int> ramSpawnTimer, zigzagSpawnTimer;
	std::vector<glm::vec2> ramSpawnLocation, zigzagSpawnLocation;
	#pragma endregion
};
#endif
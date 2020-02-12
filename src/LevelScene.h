#pragma once
#ifndef __LEVELSCENE__
#define __LEVELSCENE__

#include "PlayerShip.h"
#include "WeaponMissile.h"

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
protected:
	bool scrolling = true;
	#pragma region Game Objects
	std::vector<AI*> enemies;
	PlayerShip* player;
	std::vector<WeaponMissile*> playerWeapons;
	ShipComponent playerComponent;
	ShipComponent enemyComponent;
	//Background
	#pragma endregion
	#pragma region Spawn Timers
	int time = 0, ramIteration = 0, zigzagIteration = 0;
	std::vector<int> ramSpawnTimer, zigzagSpawnTimer;
	std::vector<glm::vec2> ramSpawnLocation, zigzagSpawnLocation;
	#pragma endregion
};
#endif
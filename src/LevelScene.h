#pragma once
#ifndef __LEVELSCENE__
#define __LEVELSCENE__
#include "Scene.h"
#include "AI.h"
#include "Player.h"

class LevelScene : public Scene
{
public:
	LevelScene();
	virtual ~LevelScene();
	void update() override;
	void DestroyEnemy(Enemy* enemy);
protected:
	bool scrolling = true;
	#pragma region Game Objects
	std::vector<AI*> enemies;
	Player* player;
	//std::vector<ObjectType*> playerWeapons;
	//Background
	#pragma endregion
	#pragma region Spawn Timers
	int time = 0, ramIteration = 0, zigzagIteration = 0;
	std::vector<int> ramSpawnTimer, zigzagSpawnTimer;
	std::vector<glm::vec2> ramSpawnLocation, zigzagSpawnLocation;
	#pragma endregion

private:
};
#endif
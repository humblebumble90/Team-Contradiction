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

class LevelScene : public Scene
{
public:
	LevelScene();
	virtual ~LevelScene();
	void update() override;
	void draw() override;
	void DestroyEnemy(Enemy* enemy);
	void DestroyWeapon(PlayerWeapon* weapon);
	void GameOver();
	glm::vec2 getPlayerPosition();
	void spawnEnemy(AI* enemyAI);
	void spawnPlayerWeapon(PlayerWeapon* playerWeapon);
	PlayerShip* getPlayerShip();
protected:
	bool scrolling = true, spawnedEnemy=false;
	#pragma region Game Objects
	std::vector<AI*> enemies;
	PlayerShip* player;
	SDL_Color yellow = { 255, 255, 0, 255 };
	Label* m_pSpeedLabel = new Label("Speed: ", "Consolas",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.45f, 10.0f), TTF_STYLE_NORMAL, false);
	Label* m_pLivesLabel = new Label("Lives: ", "Consolas",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH*0.65f, 10.0f), TTF_STYLE_NORMAL, false);
	Control_Img* m_pControl_Img = new Control_Img();
	std::vector<PlayerWeapon*> playerWeapons;

	Map* m_pMap;
	#pragma endregion
	#pragma region Spawn Timers
	int time = 0, ramIteration = 0, zigzagIteration = 0, cannoneerIteration = 0, guardianIteration = 0, diagonIteration = 0, blastIteration = 0;
	std::vector<int> ramSpawnTimer, zigzagSpawnTimer, cannoneerSpawnTimer, guardianSpawnTimer, diagonSpawnTimer, blastSpawnTimer;
	std::vector<glm::vec2> ramSpawnLocation, zigzagSpawnLocation, cannoneerSpawnLocation, guardianSpawnLocation, diagonSpawnLocation, blastSpawnLocation;
	#pragma endregion
private:
	void Damage(ShipComponent sc[2]);
};
#endif
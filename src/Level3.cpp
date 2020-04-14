#include "Level3.h"
#include "Config.h"
#include "SoundManager.h"
// Game Objects
/*Boss 0 - Ram Rush*/					#include "RamAI.h"
/*Boss 1 - Blaster Skiff*/				#include "BlasterSkiffAI.h"
//#include "ChaosAI.h"
/*Boss 2 - Firebrand*/					#include "FirebrandAI.h"
/*Boss 3 - Triple Barge (Cannon)*/		#include "CannonBargeAI.h"
/*Boss 3 - Triple Barge (Missile)*/		#include "MissileBargeAI.h"
/*Boss 3 - Triple Barge (Flamethrower)*/#include "FireBargeAI.h"
/*Boss 4 - Cannonlord*/					#include "CannonlordAI.h"
/*Boss 5 - Deathcage (last boss)*/		#include "DeathcageAI.h"
#include "Game.h"
#include "Scoreboard.h"

Level3::Level3(PlayerShip* thePlayer)
{
	level = 3;
	loadAllTextures();
	loadAllSounds();
	player = new PlayerShip(1, 5, glm::vec2(100, Config::SCREEN_HEIGHT * 0.5f));
	//player = thePlayer;
	m_pMap = new Map();
	m_pMap2 = new Map();
	m_pMap->setPosition(glm::vec2(0, 0));
	m_pMap2->setPosition(glm::vec2(1950, 0));
	//m_pSpeedLabel = new Label("Speed: ", "Consolas",
	//	24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.45f, 10.0f), TTF_STYLE_NORMAL, false);
	playSound("Level1", 999);
	//m_pLivesLabel = new Label("Lives: ", "Consolas",
	//	24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.65f, 10.0f), TTF_STYLE_NORMAL, false);
	playSound("RamRush", 0);
}

Level3::~Level3()
{
}

void Level3::clean()
{
	delete player;
	delete m_pMap;
	delete m_pMap2;
	removeAllChildren();
	
}

void Level3::handleEvents()
{
#pragma region Ram Rush
	if (ramRushTimerDelay > 0) {
		--ramRushTimerDelay;
	}
	else if (ramRushTimer > 0) {
		--ramRushTimer;
	}
	else if (bossDelayTimer > 0) {
		--bossDelayTimer;
		if (bossDelayTimer <= 0) {
			Boss1();
		}
	}
	if (ramRushTimerDelay <= 0 && ramRushTimer > 0 && ramRushTimer % 45 == 0)
	{
		int coor1 = rand() % 2;
		int coor1Decider = rand() % 2;
		coor1Decider = coor1Decider = 0 ? Config::SCREEN_WIDTH : Config::SCREEN_HEIGHT;
		coor1 = coor1 == 0 ? coor1 : coor1Decider;
		int coor2Max = coor1Decider == Config::SCREEN_WIDTH ? Config::SCREEN_HEIGHT : Config::SCREEN_WIDTH;
		int coor2 = rand() % (coor2Max + 1);
		glm::vec2 transform = coor1Decider == Config::SCREEN_WIDTH ? glm::vec2{ coor1, coor2 } : glm::vec2{ coor2, coor1 };
		enemies.push_back(new RamAI(transform));
	}
#pragma endregion
	if (bossDelayTimer <= 0 && enemies.size() == 0) {
		switch (bossIteration) {
		case 1:
			Boss2();
			break;
		case 2:
			Boss3();
			break;
		case 3:
			Boss4();
			break;
		case 4:
			Boss5();
			break;
		case 5:
			Victory();
			break;
		}
		++bossIteration;
	}
	if(player == nullptr)
	{
		std::cout << "player is " << player << std::endl;
	}
}

void Level3::start()
{
}

void Level3::Boss1()
{
	playSound("BossRush1", 999);
	spawnEnemy(new BlasterSkiffAI(glm::vec2(Config::SCREEN_WIDTH + 160, Config::SCREEN_HEIGHT / 2)));
	//spawnEnemy(new ChaosAI(glm::vec2(Config::SCREEN_WIDTH + 120, Config::SCREEN_HEIGHT / 2)));
}

void Level3::Boss2()
{
	playSound("BossRush1", 999);
	spawnEnemy(new FirebrandAI(glm::vec2(Config::SCREEN_WIDTH + 160, Config::SCREEN_HEIGHT / 2)));
}

void Level3::Boss3()
{
	playSound("BossRush2", 999);
	spawnEnemy(new CannonBargeAI(glm::vec2(Config::SCREEN_WIDTH + 120, Config::SCREEN_HEIGHT / 2)));
	spawnEnemy(new MissileBargeAI(glm::vec2(Config::SCREEN_WIDTH + 400, Config::SCREEN_HEIGHT / 2)));
	spawnEnemy(new FireBargeAI(glm::vec2(Config::SCREEN_WIDTH + 680, Config::SCREEN_HEIGHT / 2)));
}

void Level3::Boss4()
{
	playSound("BossRush2", 999);
	spawnEnemy(new CannonlordAI(glm::vec2(Config::SCREEN_WIDTH + 160, Config::SCREEN_HEIGHT / 2)));
}

void Level3::Boss5()
{
	playSound("FinalBoss", 999);
	spawnEnemy(new DeathcageAI(glm::vec2(Config::SCREEN_WIDTH + 320, Config::SCREEN_HEIGHT / 2)));
}

void Level3::Victory()
{
	//This will need to go to victory scene. Currently, it does not
}

void Level3::CheatCode()
{
	enemies.clear();
}

void Level3::loadAllTextures()
{
	std::cout << "loading all the textures" << std::endl;
	//ram
	loadTexture("../Assets/textures/Ram.png", "Ram");
	//player
	if (Game::Instance()->getGuild() == 1)
	{
		loadTexture("../Assets/textures/player1.png", "Player");
	}
	else
	{
		loadTexture("../Assets/textures/player2.png", "Player");
	}
	loadTexture("../assets/textures/shield_aurora.png", "shield_aurora");
	//background
	loadTexture("../Assets/textures/background.png", "map");
	//enemy weapons
	loadTexture("../Assets/textures/EnemyMissile.png", "EnemyMissile");
	loadTexture("../Assets/textures/EnemyCannonball.png", "EnemyCannonball");
	//blaster skiff
	//loadTexture("../Assets/textures/Chaos.png", "Chaos");
	//loadTexture("../Assets/textures/ChaosHit.png", "ChaosHit");
	loadTexture("../Assets/textures/BlasterSkiff.png", "BlasterSkiff");
	loadTexture("../Assets/textures/BlasterSkiffHit.png", "BlasterSkiffHit");
	//player weapons
	loadTexture("../Assets/textures/Missile.png", "Missile");
	loadTexture("../Assets/textures/Cannonball.png", "Cannonball");
	//firebrand
	loadTexture("../Assets/textures/Firebrand.png", "Firebrand");
	loadTexture("../Assets/textures/FirebrandHit.png", "FirebrandHit");
	loadTexture("../Assets/textures/FireBargeHit.png", "FireBargeHit");
	loadTexture("../Assets/textures/FireBarge.png", "FireBarge");
	//cannonlord
	loadTexture("../Assets/textures/Cannonlord.png", "Cannonlord");
	loadTexture("../Assets/textures/CannonlordHit.png", "CannonlordHit");
	loadTexture("../Assets/textures/CannonBarge.png", "CannonBarge");
	loadTexture("../Assets/textures/CannonBargeHit.png", "CannonBargeHit");

	//deathcage
	loadTexture("../Assets/textures/Deathcage.png", "Deathcage");
	loadTexture("../Assets/textures/DeathcageHit.png", "DeathcageHit");

	//unknown
	loadTexture("../Assets/textures/MissileBarge.png", "MissileBarge");
	loadTexture("../Assets/textures/MissileBargeHit.png", "MissileBargeHit");
	loadTexture("../Assets/textures/explosion.png", "explosion");
	std::cout << "finish loading textures" << std::endl;
}

void Level3::loadAllSounds()
{
	//sound
	std::cout << "Loading sounds" << std::endl;
	loadSound("../Assets/audio/RamRush.ogg", "RamRush", SOUND_MUSIC);
	loadSound("../Assets/audio/BossRush1.ogg", "BossRush1", SOUND_MUSIC);
	loadSound("../Assets/audio/BossRush2.ogg", "BossRush2", SOUND_MUSIC);
	loadSound("../Assets/audio/Boss.ogg", "FinalBoss", SOUND_MUSIC);
	loadSound("../Assets/audio/Explosion.ogg", "Explosion", SOUND_SFX);
	std::cout << "Finish loading sounds" << std::endl;
}

#include "Level2.h"
#include "ChaosAI.h"

Level2::Level2()
{
	level = 2;
	loadAllTextures();
	loadAllSounds();
	
	//main enemy
	cannoneerSpawnTimer =
	{
		
	};
	cannoneerSpawnLocation =
	{

	};

	zigzagSpawnTimer =
	{

	};
	zigzagSpawnLocation =
	{

	};


	guardianSpawnTimer =
	{

	};

	guardianSpawnLocation =
	{

	};


	//sub enemies
	ramSpawnTimer =
	{

	};
	ramSpawnLocation =
	{

	};

	diagonSpawnTimer =
	{

	};
	diagonSpawnLocation =
	{

	};

	blastSpawnTimer =
	{
	};
	blastSpawnLocation =
	{
	};

	//obstacles
	islandSpawnTimer =
	{
		
	};
	islandSpawnLocation =
	{
		
	};




	player = new PlayerShip(1, 5, glm::vec2(100, Config::SCREEN_HEIGHT / 2));
	//player = thePlayer
	m_pMap = new Map();
	m_pMap2 = new Map();
	m_pMap->setPosition(glm::vec2(0, 0));
	m_pMap2->setPosition(glm::vec2(1950, 0));
	//m_pSpeedLabel = new Label("Speed: ", "Consolas",
	//	24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.45f, 10.0f), TTF_STYLE_NORMAL, false);
	playSound("Level1", 999);
	//m_pLivesLabel = new Label("Lives: ", "Consolas",
	//	24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.65f, 10.0f), TTF_STYLE_NORMAL, false);
}

Level2::~Level2()
{
}

void Level2::clean()
{
	delete player;
	delete m_pMap;
	delete m_pMap2;
	removeAllChildren();
}

void Level2::handleEvents()
{
	if (time == 1 * wave)
	{
		spawnEnemy(new ChaosAI(guardianPosition));
	}
}

void Level2::start()
{
}

void Level2::loadAllTextures()
{
	//load the texture with loadTexture() with params path and id respectively
	loadTexture("../Assets/textures/player.png", "Player");
	loadTexture("../Assets/textures/background.png", "map");
	loadTexture("../Assets/textures/ship3.png", "ship3");
	loadTexture("../Assets/textures/Ram.png", "Ram");
	loadTexture("../Assets/textures/Zigzag.png", "Zigzag");
	loadTexture("../Assets/textures/Missile.png", "Missile");
	loadTexture("../Assets/textures/EnemyMissile.png", "EnemyMissile");
	loadTexture("../Assets/textures/EnemyCannonball.png", "EnemyCannonball");
	loadTexture("../Assets/textures/Cannonball.png", "Cannonball");
	loadTexture("../Assets/textures/Guardian.png", "Guardian");
	loadTexture("../Assets/textures/Blast.png", "Blast");
	loadTexture("../Assets/textures/Diagon.png", "Diagon");
	loadTexture("../Assets/textures/Cannoneer.png", "Cannoneer");
	loadTexture("../Assets/textures/Rain.png", "Rain");
	loadTexture("../Assets/textures/RainHit.png", "RainHit");
	loadTexture("../Assets/textures/Chaos.png", "Chaos");
	loadTexture("../Assets/textures/ChaosHit.png", "ChaosHit");
	loadTexture("../Assets/textures/island.png", "Island");
}

void Level2::loadAllSounds()
{
	loadSound("../Assets/audio/level1.ogg", "Level1", SOUND_MUSIC);
}

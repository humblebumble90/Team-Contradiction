#include "Level1.h"
#include "Map.h"
#include "Config.h"

Level1::Level1()
{
	loadAllTextures();
	loadAllSounds();

	int second = 60;
	int wave = 5 * second;
	glm::vec2 bottom = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT - 25);
	glm::vec2 middle = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT / 2 + 25);
	glm::vec2 top = glm::vec2(Config::SCREEN_WIDTH + 25, 25);
	glm::vec2 centerTop = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT / 4 + 25);
	glm::vec2 centerBottom = glm::vec2(Config::SCREEN_WIDTH + 25, 3 * Config::SCREEN_HEIGHT / 4 - 25);

	glm::vec2 guardianPosition = glm::vec2(Config::SCREEN_WIDTH - 20, Config::SCREEN_HEIGHT / 2);

	//main enemy
	cannoneerSpawnTimer =
	{

		//1
		wave,
		wave + 1,
		wave + 2,
		//10
		10 * wave,
		10 * wave + 1,
		10 * wave + 2,
		10 * wave + 3,
		//11
		11 * wave,
		11 * wave + 1,
		11 * wave + 2,
		11 * wave + 3,
		//12
		12 * wave,
		12 * wave + 1,
		12 * wave + 2,
		12 * wave + 3,
		//13
		13 * wave,
		13 * wave + 1,
		13 * wave + 2,
		13 * wave + 3
	};
	cannoneerSpawnLocation =
	{
		//1
		top,
		middle,
		bottom,
		//10
		top,
		centerTop,
		middle,
		centerBottom,
		//11
		centerTop,
		middle,
		centerBottom,
		bottom,
		//12
		top,
		middle,
		centerBottom,
		bottom,
		//13
		top,
		centerTop,
		middle,
		bottom
	};

	zigzagSpawnTimer =
	{
		//2
		2 * wave,
		2 * wave + 1,
		2 * wave + 2
	};
	zigzagSpawnLocation =
	{
		//2
		centerTop,
		middle,
		centerBottom
	};


	guardianSpawnTimer =
	{
		//5
		5 * wave,
		//14
		14 * wave
	};

	guardianSpawnLocation =
	{
		//5
		guardianPosition,
		//14
		guardianPosition
	};


	//sub enemies
	ramSpawnTimer =
	{
		//3
		3 * wave + 30,
		3 * wave + 31,
		3 * wave + 32,
		//13
		13 * wave + 30,
		13 * wave + 31,
		13 * wave + 32
	};

	ramSpawnLocation =
	{
		//3
		top,
		middle,
		bottom,
		//13
		top,
		middle,
		bottom
	};

	diagonSpawnTimer =
	{
		//4
		4 * wave + 30,
		4 * wave + 31,
		4 * wave + 32,
		//11
		11 * wave + 30,
		11 * wave + 31,
		11 * wave + 32
	};

	diagonSpawnLocation =
	{
		//4
		top,
		middle,
		bottom,
		//11
		top,
		middle,
		bottom
	};

	//blastSpawnTimer =
	//{
	//	//5
	//	5 * wave + 30,
	//	5 * wave + 31,
	//	//13
	//	13 * wave + 30,
	//	13 * wave + 31,
	//	13 * wave + 32
	//};

	//blastSpawnLocation =
	//{
	//	//5
	//	centerTop,
	//	centerBottom,
	//	//13
	//	centerTop,
	//	middle,
	//	centerBottom
	//};

	//obstacles
	//not yet implemented


	player = new PlayerShip(1, 5, glm::vec2(100, Config::SCREEN_HEIGHT / 2));
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

Level1::~Level1()
{
}

void Level1::clean()
{
	delete player;
	delete m_pMap;
	delete m_pMap2;
	removeAllChildren();
}

void Level1::handleEvents()
{
}

void Level1::start()
{
	
}
void Level1::loadAllTextures()
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
}

void Level1::loadAllSounds()
{
	loadSound("../Assets/audio/level1.ogg", "Level1", SOUND_MUSIC);
}

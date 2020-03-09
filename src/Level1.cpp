#include "Level1.h"
#include "Map.h"
#include "Config.h"

Level1::Level1()
{
	loadAllTextures();
	int second = 60;
	int wave = 3 * second;
	glm::vec2 bottom = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT + 25);
	glm::vec2 middle = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT / 2 + 25);
	glm::vec2 top = glm::vec2(Config::SCREEN_WIDTH + 25, 25);
	glm::vec2 centerTop = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT / 4 + 25);
	glm::vec2 centerBottom = glm::vec2(Config::SCREEN_WIDTH + 25, 3 * Config::SCREEN_HEIGHT / 4 + 25);

	//main enemy
	cannoneerSpawnTimer =
	{

		//1
		wave,
		wave + 1,
		wave + 2,
		//7
		7 * wave,
		7 * wave + 1,
		7 * wave + 2,
		7 * wave + 3,
		//8
		8 * wave,
		8 * wave + 1,
		8 * wave + 2,
		8 * wave + 3,
		//9
		9 * wave,
		9 * wave + 1,
		9 * wave + 2,
		9 * wave + 3,
		//10
		10 * wave,
		10 * wave + 1,
		10 * wave + 2,
		10 * wave + 3,
	};
	cannoneerSpawnLocation =
	{
		//1
		top,
		middle,
		bottom,
		//7
		top,
		centerTop,
		middle,
		centerBottom,
		//8
		centerTop,
		middle,
		centerBottom,
		bottom,
		//9
		top,
		middle,
		centerBottom,
		bottom,
		//10
		top,
		centerTop,
		middle,
		bottom,
	};

	zigzagSpawnTimer =
	{
		//2
		2 * wave,
		2 * wave + 1,
		2 * wave + 2,
	};
	zigzagSpawnLocation =
	{
		//2
		centerTop,
		middle,
		centerBottom,
	};


	guardianSpawnTimer =
	{
		//5
		5 * wave,
		//11
		11 * wave,
	};

	guardianSpawnLocation =
	{
		//5
		middle,
		//11
		middle
	};


	//sub enemies
	ramSpawnTimer =
	{
		//3
		3 * wave + 30,
		3 * wave + 31,
		3 * wave + 32,
		//10
		10 * wave + 30,
		10 * wave + 31,
		10 * wave + 32,
	};

	ramSpawnLocation =
	{
		//3
		top,
		middle,
		bottom,
		//10
		top,
		middle,
		bottom,
	};

	diagonSpawnTimer =
	{
		//4
		4 * wave + 30,
		4 * wave + 31,
		4 * wave + 32,
		//8
		8 * wave + 30,
		8 * wave + 31,
		8 * wave + 32,
	};

	diagonSpawnLocation =
	{
		//4
		top,
		middle,
		bottom,
		//8
		top,
		middle,
		bottom,
	};

	blastSpawnTimer =
	{
		//5
		5 * wave + 30,
		5 * wave + 31,
		//11
		11 * wave + 30,
		11 * wave + 31,
		11 * wave + 32,
	};

	blastSpawnLocation =
	{
		//5
		centerTop,
		centerBottom,
		//11
		centerTop,
		middle,
		centerBottom,
	};

	//obstacles
	//not yet implemented


	player = new PlayerShip(1, 3, glm::vec2(100, Config::SCREEN_HEIGHT / 2));
	m_pMap = new Map();
}

Level1::~Level1()
{
}

void Level1::clean()
{
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
	loadTexture("../Assets/textures/map.jpg", "map");
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

#include "Level2.h"
#include "ChaosAI.h"
#include "Game.h"
#include "Scoreboard.h"

Level2::Level2()
{
	level = 2;
	loadAllTextures();
	loadAllSounds();
	
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
		13 * wave + 3,
		//30
		30 * wave,
		30 * wave + 1,
		30 * wave + 2,
		//31
		31 * wave,
		31 * wave + 1,
		31 * wave + 2,
		//32
		32 * wave,
		32 * wave + 1,
		32 * wave + 2,
		//35
		35 * wave,
		35 * wave + 1,
		35 * wave + 2,
		35 * wave + 3,
		35 * wave + 4
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
		bottom,
		//30
		top,
		middle,
		bottom,
		//31
		top,
		middle,
		bottom,
		//32
		top,
		middle,
		bottom,
		//35
		top,
		centerTop,
		middle,
		centerBottom,
		bottom,
	};

	zigzagSpawnTimer =
	{
		//2
		2 * wave,
		2 * wave + 1,
		//20
		20 * wave,
		20 * wave + 1,
		20 * wave + 2,
		//21
		21 * wave,
		21 * wave + 1,
		21 * wave + 2,
		//22
		22 * wave,
		22 * wave + 1,
		22 * wave + 2,
		//23
		23 * wave,
		23 * wave + 1,
		23 * wave + 2,
		//30
		30 * wave + 4,
		30 * wave + 5,
		//31
		31 * wave + 4,
		30 * wave + 5,
		//33
		33 * wave,
		33 * wave + 1,
		33 * wave + 2,
		//34
		34 * wave,
		34 * wave + 1,
		34 * wave + 2,
	};
	zigzagSpawnLocation =
	{
		//2
		middle,
		bottom,
		//20
		middle,
		centerBottom,
		bottom,
		//21
		middle,
		centerBottom,
		bottom,
		//22
		middle,
		centerBottom,
		bottom,
		//23
		middle,
		centerBottom,
		bottom,
		//30
		middle,
		bottom,
		//31
		middle,
		bottom,
		//33
		middle,
		centerBottom,
		bottom,
		//34
		middle,
		centerBottom,
		bottom,
	};


	guardianSpawnTimer =
	{
		//5
		5 * wave,
		//14
		14 * wave,
		//24
		24 * wave,
		//33
		33 * wave,
		//35
		35 * wave
	};

	guardianSpawnLocation =
	{
		//5
		guardianPosition,
		//14
		guardianPosition,
		//24
		guardianPosition,
		//33
		guardianPosition,
		//35
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
		13 * wave + 32,
		//16
		16 * wave + 60,
		16 * wave + 61,
		16 * wave + 120,
		16 * wave + 121,
		16 * wave + 180,
		16 * wave + 181,
		16 * wave + 240,
		16 * wave + 241,
		16 * wave + 300,
		16 * wave + 301,
		16 * wave + 360,
		16 * wave + 361,
		//21
		21 * wave + 30,
		21 * wave + 40,
		21 * wave + 50,
		21 * wave + 60,
		//22
		22 * wave + 70,
		22 * wave + 80,
		22 * wave + 90,
		22 * wave + 100,
		//26
		26 * wave + 60,
		26 * wave + 61,
		26 * wave + 120,
		26 * wave + 121,
		26 * wave + 180,
		26 * wave + 181,
		26 * wave + 240,
		26 * wave + 241,
		26 * wave + 300,
		26 * wave + 301,
		26 * wave + 360,
		26 * wave + 361,
		//31
		31 * wave + 30,
		31 * wave + 60,
		31 * wave + 90,
		31 * wave + 120,
		31 * wave + 150,
		31 * wave + 180,
		31 * wave + 210,
		//33
		33 * wave + 30,
		33 * wave + 60,
		33 * wave + 90,
		33 * wave + 120,
		33 * wave + 150,
		33 * wave + 180,
		33 * wave + 210,
		//36
		36 * wave + 60,
		36 * wave + 61,
		36 * wave + 120,
		36 * wave + 121,
		36 * wave + 180,
		36 * wave + 181,
		36 * wave + 240,
		36 * wave + 241,
		36 * wave + 300,
		36 * wave + 301,
		36 * wave + 360,
		36 * wave + 361,
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
		bottom,
		//16
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		//21
		top,
		centerTop,
		centerBottom,
		bottom,
		//22
		top,
		centerTop,
		centerBottom,
		bottom,
		//26
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		//31
		top,
		centerTop,
		top,
		centerTop,
		middle,
		centerBottom,
		bottom,
		centerBottom,
		bottom,
		//33
		top,
		centerTop,
		top,
		centerTop,
		middle,
		centerBottom,
		bottom,
		centerBottom,
		bottom,
		//26
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
		top,
		bottom,
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
		11 * wave + 32,
		//23
		23 * wave + 30,
		23 * wave + 50,
		23 * wave + 70,
		23 * wave + 90,
		//24
		24 * wave + 30,
		24 * wave + 50,
		24 * wave + 70,
		24 * wave + 90,
		//31
		31 * wave + 70,
		31 * wave + 100,
		31 * wave + 130,
		//32
		32 * wave + 70,
		32 * wave + 100,
		32 * wave + 130,
		//33
		33 * wave + 70,
		33 * wave + 100,
		33 * wave + 130,
		//34
		34 * wave + 70,
		34 * wave + 100,
		34 * wave + 130,
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
		bottom,
		//23
		bottom,
		bottom,
		bottom,
		bottom,
		//24
		top,
		top,
		top,
		top,
		//31
		top,
		top,
		top,
		//32
		bottom,
		bottom,
		bottom,
		//33
		top,
		top,
		top,
		//34
		bottom,
		bottom,
		bottom,
	};

	blastSpawnTimer =
	{
		//5
		5 * wave + 30,
		5 * wave + 31,
		//13
		13 * wave + 30,
		13 * wave + 31,
		//32
		32 * wave + 30,
		32 * wave + 31,
		//34
		34 * wave + 30,
		34 * wave + 31,
	};

	blastSpawnLocation =
	{
		//5
		centerTop,
		centerBottom,
		//13
		centerTop,
		centerBottom,
		//32
		centerTop,
		centerBottom,
		//32
		centerTop,
		centerBottom
	};

	//obstacles
	islandSpawnTimer =
	{
		//8
		8 * wave,
		8 * wave + 1,
		//18
		18 * wave,
		18 * wave + 1,
		//28
		28 * wave,
		28 * wave + 1,
		//38
		38 * wave,
		38 * wave + 1,
	};

	islandSpawnLocation =
	{
		//8
		topIslandPosition,
		bottomIslandPosition,
		//18
		topIslandPosition,
		bottomIslandPosition,
		//28
		topIslandPosition,
		bottomIslandPosition,
		//38
		topIslandPosition,
		bottomIslandPosition
	};



	player = new PlayerShip(1, 5, glm::vec2(100, Config::SCREEN_HEIGHT * 0.5f));
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
	if (time == 40 * wave)
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
	if (Game::Instance()->getGuild() == 1)
	{
		loadTexture("../Assets/textures/player1.png", "Player");
	}
	else
	{
		loadTexture("../Assets/textures/player2.png", "Player");
	}
	loadTexture("../assets/textures/shield_aurora.png", "shield_aurora");
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
	loadTexture("../Assets/textures/explosion.png", "explosion");
}

void Level2::loadAllSounds()
{
	loadSound("../Assets/audio/level1.ogg", "Level1", SOUND_MUSIC);
}

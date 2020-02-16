#include "Level1.h"
#include "Map.h"

Level1::Level1()
{
	int second = 60;
	glm::vec2 bottom = glm::vec2(1650, 850);
	glm::vec2 middle = glm::vec2(1650, 450);
	glm::vec2 top = glm::vec2(1650, 50);
	ramSpawnTimer =
	{
		10 * second,
		10 * second + 1,
		10 * second + 2,
		15 * second,
		15 * second + 1,
		15 * second + 2,
		30 * second,
		30 * second + 1,
		30 * second + 2,
		35 * second,
		35 * second + 1,
		35 * second + 2,
		50 * second,
		50 * second + 1,
		50 * second + 2,
		55 * second,
		55 * second + 1,
		55 * second + 2,
	};
	ramSpawnLocation =
	{
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
	};
	zigzagSpawnTimer =
	{
		20 * second,
		20 * second + 1,
		20 * second + 2,
		25 * second,
		25 * second + 1,
		25 * second + 2,
		40 * second,
		40 * second + 1,
		40 * second + 2,
		45 * second,
		45 * second + 1,
		45 * second + 2,
		60 * second,
		60 * second + 1,
		60 * second + 2,
		65 * second,
		65 * second + 1,
		65 * second + 2,
	};
	zigzagSpawnLocation =
	{
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
		top,
		middle,
		bottom,
	};

	player = new PlayerShip(1, 3, glm::vec2(0, 0));
	m_pMap = new Map();
}

Level1::~Level1()
{
}

void Level1::draw()
{
	player->draw();
	m_pMap->draw();
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

void Level1::update()
{
	m_pMap->update();
}
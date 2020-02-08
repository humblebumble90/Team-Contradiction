#include "Level3.h"
#include "Config.h"

Level3::Level3(Player* thePlayer)
{
	player = thePlayer;
}

Level3::~Level3()
{
}

void Level3::draw()
{
	//Background
	//UI

	player->draw();
	//Player Weapons
	for (AI* a : enemies) {
		a->GetParent().draw();
	}
}

void Level3::update()
{
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
	if (ramRushTimerDelay <= 0 && ramRushTimer > 0 && ramRushTimer % 12 == 0)
	{
		int coor1 = rand() % 2;
		int coor1Decider = rand() % 2;
		coor1Decider = coor1Decider = 0 ? Config::SCREEN_WIDTH : Config::SCREEN_HEIGHT;
		coor1 = coor1 == 0 ? coor1 : coor1Decider;
		int coor2Max = coor1Decider == Config::SCREEN_WIDTH ? Config::SCREEN_HEIGHT : Config::SCREEN_WIDTH;
		int coor2 = rand() % (coor2Max + 1);
		glm::vec2 transform = coor1Decider == Config::SCREEN_WIDTH ? glm::vec2{coor1, coor2} : glm::vec2{coor2, coor1};
		enemies.push_back(new RamAI(transform));
	}
}

void Level3::clean()
{
}

void Level3::handleEvents()
{
}

void Level3::start()
{
}

void Level3::Boss1()
{
}

void Level3::Boss2()
{
}

void Level3::Boss3()
{
}

void Level3::Boss4()
{
}

void Level3::Boss5()
{
}

void Level3::Victory()
{
}

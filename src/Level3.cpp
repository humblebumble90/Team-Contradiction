#include "Level3.h"

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
	if (ramRushTimerDelay <= 0 && ramRushTimer > 0 && ramRushTimer % 12 == 0) {
		glm::vec2 transform /* = (something to grab random numbers)*/;
		//enemies.push_back(RamAI(transform)); ---Wants me to use the new keyword. I don't want to use said keyword
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

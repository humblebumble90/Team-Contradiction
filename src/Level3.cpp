#include "Level3.h"
#include "Config.h"
#include "SoundManager.h"

Level3::Level3(PlayerShip* thePlayer)
{
	player = thePlayer;
	TheSoundManager::Instance()->load("../Assets/audio/RamRushTemporary.ogg", "RamRush", SOUND_MUSIC);
	TheSoundManager::Instance()->load("../Assets/audio/BossRush1Temporary.ogg", "BossRush1", SOUND_MUSIC);
	TheSoundManager::Instance()->load("../Assets/audio/BossRush2Temporary.ogg", "BossRush2", SOUND_MUSIC);
	TheSoundManager::Instance()->load("../Assets/audio/FinalBossTemporary.ogg", "FinalBoss", SOUND_MUSIC);
	TheSoundManager::Instance()->playMusic("RamRush", 0);
}

Level3::~Level3()
{
}

void Level3::draw()
{
	//Background
	//UI

	player->draw();
	for (WeaponMissile* wm : playerWeapons) {
		wm->draw();
	}
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
	TheSoundManager::Instance()->playMusic("BossRush1", 999);
}

void Level3::Boss2()
{
}

void Level3::Boss3()
{
	TheSoundManager::Instance()->playMusic("BossRush2", 999);
}

void Level3::Boss4()
{
}

void Level3::Boss5()
{
	TheSoundManager::Instance()->playMusic("FinalBoss", 999);
}

void Level3::Victory()
{
	//This will need to play victory music. Currently, it does not
}

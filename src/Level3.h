#pragma once
#ifndef __LEVEL3__
#define __LEVEL3__

#include "LevelScene.h"

class Level3 : public LevelScene
{
public:/*
	friend class RamAI;
	friend class BlasterSkiffAI;
	friend class FirebrandAI;
	friend class CannonBargeAI;
	friend class MissileBargeAI;
	friend class FireBargeAI;
	friend class CannonlordAI;
	friend class DeathcageAI;
	friend class AI;*/
	Level3(PlayerShip* thePlayer);
	~Level3();

	// Inherited via Scene
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// Specific to Level 3
	void Boss1(); //Ends the Ram Rush, changes the music, then spawns Blaster Skiff
	void Boss2(); //Spawns Firebrand
	void Boss3(); //Changes music, then spawns Triple Barge
	void Boss4(); //Spawns Cannonlord
	void Boss5(); //Changes music, then spawns Deathcage
	void Victory(); //Switches the scene to the VictoryScreen
private:
	//Timers
	int ramRushTimerDelay = 180, ramRushTimer = 900, bossDelayTimer = 60, bossDelayTimerReset = 60;
};

#endif
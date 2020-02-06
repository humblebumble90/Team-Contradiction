#pragma once
#ifndef __LEVEL3__
#define __LEVEL3__

#include "Scene.h"

// Game Objects
/*Boss 0 - Ram Rush*/					#include "RamAI.h"
/*Boss 1 - Blaster Skiff*/				#include "BlasterSkiffAI.h"
/*Boss 2 - Firebrand*/					#include "FirebrandAI.h"
/*Boss 3 - Triple Barge (Cannon)*/		#include "CannonBargeAI.h"
/*Boss 3 - Triple Barge (Missile)*/		#include "MissileBargeAI.h"
/*Boss 3 - Triple Barge (Flamethrower)*/#include "FireBargeAI.h"
/*Boss 4 - Cannonlord*/					#include "CannonlordAI.h"
/*Boss 5 - Deathcage (last boss)*/		#include "DeathcageAI.h"

class Level3 : public Scene
{
public:
	Level3(Player* thePlayer);
	~Level3();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// Specific to Level 3
	void Boss1(); //Ends the Ram Rush, changes the music, then spawns Blaster Skiff
	void Boss2(); //Spawns Firebrand
	void Boss3(); //Changes music, then spawns Triple Barge
	void Boss4(); //Spawns Cannonlord
	void Boss5(); //Changes music, then spawns Deathcage
	void Victory(); //Switches the scene to the VictoryScreen
private:
	// GameObjects
	std::vector<AI*> enemies;
	Player* player;
	//std::vector<ObjectType*> playerWeapons;
	//Background

	//Timers
	int ramRushTimerDelay = 180, ramRushTimer = 900, bossDelayTimer = 60, bossDelayTimerReset = 60;
};

#endif
/*
Josh's notes

- Scrolling should be a bool in Scene. While true, the screen scrolls. It's protected with a getter, meaning that scenes can turn on/off scrolling
- Defeat() should be a public method in scene, which brings the player to the defeat scene



*/
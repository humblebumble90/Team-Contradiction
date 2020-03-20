#include "ChaosAI.h"
#include "Cannon.h"
#include "MissileLauncher.h"
#include "BasicBody.h"
#include "Game.h"

ChaosAI::ChaosAI(glm::vec2 transform)
{
	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		Cannon(), BasicBody(), MissileLauncher(),
		Cannon(), BasicBody(), MissileLauncher(),
		Cannon(), BasicBody(), MissileLauncher()
	};
#pragma endregion
	parent = new Enemy(new Frame(80, //Enemy is 240px by 240px
		build, 3, 3), 100, //Will tweak if 100 health proves to be too much or too little
		this, transform, "Chaos");
	target = glm::vec2(Config::SCREEN_WIDTH-220, Config::SCREEN_HEIGHT / 2);
	score = 10000;
	isBoss = false; //This is written so it'll utilize AABB Collision. This may cause errors with player getting Shields
	speed.y = TheGame::Instance()->getPlayerPosition().y > parent->getPosition().y ? baseSpeed : -baseSpeed;
}

ChaosAI::~ChaosAI()
{
}

void ChaosAI::SecondaryFunction()
{
	#pragma region Set Phase
	if ((phase == 0 && parent->getHealth() <= phase1) || (phase == 1 && parent->getHealth() <= phase2)) {
		++phase;
		if (phase == 1) {
			canFire = false;
			speed.y == 0;
			speed.x = -baseSpeed;
		}
	}
	#pragma endregion
	if (speed.x < 0) {
		if (parent->getPosition().x <= 0) {
			speed.x == 0;
			speed.y = TheGame::Instance()->getPlayerPosition().y > parent->getPosition().y ? baseSpeed : -baseSpeed;
			reverseTimer = reverseTimerReset;
			timer = timerReset;
			canFire = true;
		}
	}
	#pragma region Firing
	if (canFire) {
		--timer;
		if (timer <= 0) {
			if (phase == 0) {
				for (Weapon w : parent->GetFrame()->GetWeapons()) {
					if (w.getName() == "Cannon") {
						w.Fire();
					}
				}
				speed.y = TheGame::Instance()->getPlayerPosition().y > parent->getPosition().y ? baseSpeed : -baseSpeed;
				reverseTimer = reverseTimerReset;
			}
			else if (phase == 1) {

			}
			else {

			}
			timer = timerReset;
		}
	}
	#pragma endregion
#pragma region Phase 2
	/*
	The music increases in tempo at the start of this phase
	Phase 2 begins at 75 hp, and causes the boss to travel to X: 0.
	Once there, it will continue as in phase 1, but instead, it will fire its missiles
	After 10 seconds, rams back to its original spot
	Continues as in Phase 1, but also uses Missile Launchers
	*/
#pragma endregion
#pragma region Phase 3
	/*
	The music increases in tempo once more upon reaching this phase
	Phase 3 begins at 40 hp, and causes the boss to ram and rotate
	It continues as in Phase 2 for 10 seconds, but does so rotated 180 degrees
	After the 10 seconds, it rams towards the center of the screen
	It stops after getting 1/4 of the way across the screen, then rotates around the center
	During this time, it fires all its weapons
	*/
#pragma endregion

}

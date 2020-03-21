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
		canFire = false;
		speed.y == 0;
		speed.x = -baseSpeed;
		rotate = phase == 2;
	}
	#pragma endregion
	#pragma region Rotation
	if (rotate) {
		if (!canFire) {
			int i = rotation % 2 == 0 ? 1 : 2;
			rotation += i;
			rotate = rotation == 180 && canFire == false;
		}
		else {
			++rotation;
			if (rotation >= 360) {
				rotation -= 360;
			}
			int i = rotation >= 180 ? rotation - 180 : rotation + 180;
			float angle = i * M_PI / 180;
			parent->setPosition(glm::vec2(
				cos(angle) * (parent->getPosition().x - (Config::SCREEN_WIDTH / 2)) - sin(angle) * (parent->getPosition().y - (Config::SCREEN_HEIGHT / 2)) + (Config::SCREEN_WIDTH / 2),
				sin(angle) * (parent->getPosition().x - (Config::SCREEN_WIDTH / 2)) - cos(angle) * (parent->getPosition().y - (Config::SCREEN_HEIGHT / 2)) + (Config::SCREEN_HEIGHT / 2)
			));
		}
	}
	#pragma endregion
	#pragma region Ramming
	if (speed.x != 0) {
		if ((parent->getPosition().x <= 0 && speed.x < 0) || (speed.x > 0 && parent->getPosition().x >= Config::SCREEN_WIDTH - 220)) {
			if (speed.x < 0) {
				reverseTimer = reverseTimerReset;
			}
			speed.x == 0;
			speed.y = TheGame::Instance()->getPlayerPosition().y > parent->getPosition().y ? baseSpeed : -baseSpeed;
			timer = timerReset;
			canFire = true;
		}
	}
	#pragma endregion
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
			}
			else if (phase == 1) {
				for (Weapon w : parent->GetFrame()->GetWeapons()) {
					if (w.getName() == "MissileLauncher") {
						w.Fire();
					}
					else if (w.getName() == "Cannon" && phase == 1 && reverseTimer == 0) {
						w.Fire();
					}
				}
			}
			else {
				Vector2 up = Vector2(0 + rotation / 90, -1 + rotation / 90);
				Vector2 down = Vector2(0 - rotation / 90, 1 - rotation / 90);
				Vector2 left = Vector2(-1 + rotation / 90, 0 - rotation / 90);
				Vector2 right = Vector2(1 - rotation / 90, 0 + rotation / 90);
				Vector2 direction;
				if (rotation < 90) {
					direction = left;
				}
				else if (rotation < 180) {
					direction = up;
				}
				else if (rotation < 270) {
					direction = right;
				}
				else {
					direction = down;
				}
				for (Weapon w : parent->GetFrame()->GetWeapons()) {
					if (w.getName() == "MissileLauncher") {
						w.Fire();
					}
					else {
						((Cannon&)w).Fire(direction);
					}
				}
			}
			timer = timerReset;
		}
	}
	#pragma endregion
	#pragma region End Left-Side Phase
	if (reverseTimer > 0) {
		--reverseTimer;
		if (reverseTimer <= 0) {
			canFire = false;
			speed.x = baseSpeed;
			speed.y = 0;
			if (phase == 2) {
				finalPhase = true;
			}
		}
	}
	#pragma endregion
	#pragma region Intro to Final Phase
	if (finalPhase) {
		if (parent->getPosition().x >= 400) {
			finalPhase = false;
			rotate = true;
			speed.x = 0;
			speed.y = 0;
			timer = 1;
			canFire = true;
			reverseTimer = 0;
		}
	}
	#pragma endregion
}

int ChaosAI::getRotation()
{
	return rotation;
}

bool ChaosAI::getFire()
{
	//NOTE: This method alwars returns the OPPOSITE. This is to avoid problems in Enemy->Damage(int i)
	return canFire ? false : true;
}

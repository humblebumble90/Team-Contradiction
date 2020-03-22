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
		build, 3, 3), 41, //Will tweak if 100 health proves to be too much or too little
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
			rotate = rotation < 180;
		}
		else {
			++rotation;
			if (rotation >= 360) {
				rotation -= 360;
			}
			float angle = rotation * M_PI / 180;
			int posX = parent->getPosition().x, posY = parent->getPosition().y;
			parent->setPosition(glm::vec2(
				(Config::SCREEN_WIDTH / 2) + (320 * cos(angle)),
				(Config::SCREEN_HEIGHT / 2) + (320 * sin(angle))
				//center + distance * cos(angle), center + distance * sin(angle)
			));
		}
	}
	#pragma endregion
	#pragma region Ramming
	if (speed.x != 0) {
		if (((parent->getPosition().x <= 0 && speed.x < 0) || (speed.x > 0 && parent->getPosition().x >= Config::SCREEN_WIDTH - 220)) && !canFire) {
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
				speed.y = TheGame::Instance()->getPlayerPosition().y > parent->getPosition().y ? baseSpeed : -baseSpeed;
			}
			else {
				int Rotation = rotation;
				while (Rotation >= 90) {
					Rotation -= 90;
				}
				float f = 0.01111111f;
				f *= Rotation;
				Vector2 up = Vector2(0 + f, -1 + f);
				Vector2 down = Vector2(0 - f, 1 - f);
				Vector2 left = Vector2(-1 + f / 90, 0 - f);
				Vector2 right = Vector2(1 - f / 90, 0 + f);
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
						if (parent->getPosition().x == 0) {
							speed.y = TheGame::Instance()->getPlayerPosition().y > parent->getPosition().y ? baseSpeed : -baseSpeed;
						}
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
				if (parent->getPosition().y > Config::SCREEN_HEIGHT / 2) {
					speed.y = -baseSpeed;
				}
				else if (parent->getPosition().y < Config::SCREEN_HEIGHT / 2) {
					speed.y = baseSpeed;
				}
			}
		}
	}
	#pragma endregion
	#pragma region Intro to Final Phase
	if (finalPhase) {
		if (parent->getPosition().y == Config::SCREEN_HEIGHT / 2) {
			speed.y == 0;
		}
		if (parent->getPosition().x >= 400) {
			finalPhase = false;
			rotate = true;
			speed.x = 0;
			speed.y = 0;
			timer = 1;
			canFire = true;
			reverseTimer = 0;
			parent->setPosition(glm::vec2(400, Config::SCREEN_HEIGHT / 2));
		}
	}
	#pragma endregion
	if (((!canFire && !finalPhase) || (rotate && canFire)) && speed.y != 0) {
		speed.y = 0;
	}
	else if (canFire && speed.x != 0) {
		speed.x = 0;
	}
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

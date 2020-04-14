#pragma once
#ifndef __PlayerShip__
#define __PlayerShip__

#include "TextureManager.h"
#include <iostream>
#include <experimental/coroutine>
#include "Frame.h"
#include "Move.h"
#include <SDL_hints.h>
#include <glm/detail/type_vec2.hpp>
#include "PlayerWeaponTypes.h"

class PlayerShip : public DisplayObject {
public:
	friend class LevelScene;
	PlayerShip(int playerHealth, int playerLives, glm::vec2 targetTransform);
	~PlayerShip();

	void Damage(int i) override;
	Frame* GetFrame();

	// Draw the object
	void draw() override;

	// Update the object
	void update() override;

	// remove anything that needs to be deleted
	void clean() override;

	//Invincibility
	bool getInvincibility();
	void invincible();

	//Moving
	void move(Move newMove);
	//getter and setter of playerMoving boolean
	bool getIsMoving();
	void setIsMoving(bool newState);
	
	Frame* frame;
	
	//getter and setter of player lives
	int getPlayerLives();
	void setPlayerLives(int num);
	void adjustPlayerLives(int num);
	//getter and setter of player score
	int getScore();
	void addScore(int num);
	//Getter and setter of player speed
	float getPlayerSpeed();
	void setPlayerSpeed(float num);

	void setKillCounter(int num);
	void setBossKillCounter(int num);

	bool getShieldAvailable();
	void setShieldAvailable(bool newState);

	void initializeKillCounter();

	void changeWeapon(PlayerWeaponType weapon);

	bool getPlayerDead();
	void setPlayerDead(bool newState);
private:
	Uint8 m_alpha;
	float m_maxSpeed;
	bool m_isMoving;
	//Invincibility
	bool shieldAvailable;
	bool inv;
	int endInvincibleTime;
	//Player stats
	int playerHealth;
	int playerLives;
	int playerScore;
	int playerHighScore;
	std::string name;
	const static int defaultAlpha = 255;
	void checkBound();
	//KillCounter
	int killCounter;
	int getKillCounter();
	int bossKillCounter;
	int getBossKillCounter();
	bool dead;
};


#endif /* defined (__PlayerShip__) */
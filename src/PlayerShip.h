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

	//Moving
	void move(Move newMove);
	//getter and setter of playerMoving boolean
	bool getIsMoving();
	void setIsMoving(bool newState);
	
	Frame* frame;

	//getter and setter of player lives
	int getPlayerLives();
	void setPlayerLives(int num);
	//getter and setter of player score
	int getPlayerScore();
	void setPlayerScore(int num);
	//Getter and setter of player speed
	float getPlayerSpeed();
	void setPlayerSpeed(float num);

	void setKillCounter(int num);

	bool getShieldAvailable();
	void setShieldAvailable(bool newState);

	void initializeKillCounter();
private:
	Uint8 m_alpha;
	float m_maxSpeed;
	bool m_isMoving;
	
	bool shieldAvailable;
	bool inv;
	int endInvincibleTime;
	
	int playerHealth;
	int playerLives;
	int playerScore;
	std::string name;
	const static int defaultAlpha = 255;
	void invincible();
	void checkBound();
	//KillCounter
	int killCounter;
	int getKillCounter();
};


#endif /* defined (__PlayerShip__) */
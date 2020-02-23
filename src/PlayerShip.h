#pragma once
#ifndef __PlayerShip__
#define __PlayerShip__

#include "TextureManager.h"
#include <iostream>
#include <experimental/coroutine>
#include "Frame.h"
#include "Move.h"

class PlayerShip : public DisplayObject {
public:
	friend class LevelScene;
	PlayerShip(int playerHealth, int playerLives, glm::vec2 targetTransform);
	~PlayerShip();

	void Damage(int i) override;
	Frame GetFrame();

	glm::vec2 getPlayerMaxSpeedX();
	glm::vec2 maxSpeedX;
	glm::vec2 getPlayerminSpeedX();
	glm::vec2 minSpeedX;
	glm::vec2 getPlayerMaxSpeedY();
	glm::vec2 maxSpeedY;
	glm::vec2 getPlayerMinSpeedY();
	glm::vec2 minSpeedY;

	// Draw the object
	void draw() override;

	// Update the object
	void update() override;

	// remove anything that needs to be deleted
	void clean() override;

	//Invincibility
	bool getInvincibility();
	bool inv = false;
	void invincible();

	//Moving
	void move(Move newMove);
	//getters and setters
	bool getIsMoving();
	void setIsMoving(bool newState);
private:
	float m_maxSpeed;
	bool m_isMoving;
	int endInvincibleTime;
	int playerHealth;
	int playerLives;
	Frame frame;
	std::string name;
	LevelScene* m_pLevelScene;
};


#endif /* defined (__PlayerShip__) */
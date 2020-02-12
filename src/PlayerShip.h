#pragma once
#ifndef __PlayerShip__
#define __PlayerShip__

#include "TextureManager.h"
#include "LevelScene.h"
#include <iostream>
#include <experimental/coroutine>

class PlayerShip : public GameObject {
public:
	friend class Frame;
	PlayerShip(Frame playerFrame, int playerHealth, int playerLives, glm::vec2 targetTransform);
	~PlayerShip();

	void Damage(int i);
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
private:
	int endInvincibleTime;
	int playerHealth;
	int playerLives;
	Frame frame;
	std::string name;
	LevelScene* m_pLevelScene;
};


#endif /* defined (__PlayerShip__) */
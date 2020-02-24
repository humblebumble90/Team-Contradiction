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
	Frame* GetFrame();

	// Draw the object
	void draw() override;

	// Update the object
	void update() override;

	// remove anything that needs to be deleted
	void clean() override;

	//Invincibility
	bool getInvincibility();
	bool inv;
	void invincible();

	//Moving
	void move(Move newMove);
	//getters and setters
	bool getIsMoving();
	void setIsMoving(bool newState);
	Frame* frame;
private:
	Uint8 m_alpha;
	float m_maxSpeed;
	bool m_isMoving;
	int endInvincibleTime;
	int m_playerHealth;
	int m_playerLives;
	std::string name;
};


#endif /* defined (__PlayerShip__) */
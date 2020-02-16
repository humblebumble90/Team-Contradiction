#pragma once
#ifndef __PLAYER__
#define __PLAYER__
#include "DisplayObject.h"
#include "Move.h"

class PlayerShip : public DisplayObject
{
public:
	//Constructor
	PlayerShip();
	~PlayerShip();

	//default methods
	void draw() override;
	void update() override;
	void clean() override;
	//created methods
	void move(Move newMove);//moves the player
private:
	float m_speedMultiplier;
	void checkBounds();
};

#endif
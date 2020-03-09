#pragma once
#include "DisplayObject.h"
#ifndef __POWER_UP__
#define __POWER_UP__
class Power_Up:public DisplayObject
{
	Power_Up();
	~Power_Up();

public:
	void draw() override;
	void update() override;
	void clean() override;
	bool getCollided();
	void setCollided(bool newState);
private:
	bool collided;
	void move();
};
#endif /*Defined (__POWER_UP__)*/
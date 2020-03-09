#pragma once
#include "DisplayObject.h"
#ifndef __SHIELD__
#define __SHIELD__
class Shield:public DisplayObject
{
public:
	Shield();
	~Shield();
	void draw() override;
	void move();
	void update() override;
	void clean() override;
	bool getCollided();
	void setCollided(bool newState);
private:
	bool collided;
};
#endif  /*Defined (__SHIELD__)*/
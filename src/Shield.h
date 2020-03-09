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
	void update() override;
	void clean() override;
	bool getCollided();
	void setCollided(bool newState);
private:
	bool collided;
};
#endif  /*Defiend (__SHIELD__)*/
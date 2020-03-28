#pragma once
#include "DisplayObject.h"
#ifndef __SHIELD__
#define __SHIELD__
class Shield:public DisplayObject
{
public:
	Shield(std::string id);
	~Shield();
	void draw() override;
	void move();
	void update() override;
	void clean() override;
	//bool getCollided();
	//void setCollided(bool newState);
	std::string getID();
private:
	bool collided;
	std::string ID;
};
#endif  /*Defined (__SHIELD__)*/
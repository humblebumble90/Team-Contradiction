#pragma once
#ifndef __SHIPCOMPONENT__
#define __SHIPCOMPONENT__
#include "glm/vec2.hpp"
#include "Frame.h"
class ShipComponent
{
public:
	ShipComponent();
	virtual ~ShipComponent();
	glm::vec2 getPosition();
	void setID(glm::vec2 id);
	Frame* getParent();
	void setParent(Frame* frame);
	std::string getName();
	glm::vec2 getID();
protected:
	Frame* parent;
	std::string name;
private:
	glm::vec2 iD = { -1,-1 };
};
#endif
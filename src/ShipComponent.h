#pragma once
#ifndef __SHIPCOMPONENT__
#define __SHIPCOMPONENT__
#include "Frame.h"
class ShipComponent
{
public:
	ShipComponent();
	virtual ~ShipComponent();
	glm::vec2 getPosition();
	void setID(int x, int y);
	Frame getParent();
protected:
	Frame parent;
private:
	glm::vec2 iD = { -1, -1 };
};
#endif
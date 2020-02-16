#pragma once
#ifndef __BASICBODY__
#define __BASICBODY__
#include "ShipComponent.h"
class BasicBody : public ShipComponent
{
public:
	BasicBody();
	~BasicBody();
	void Damage(int i);
};
#endif
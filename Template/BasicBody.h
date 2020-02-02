#pragma once
#ifndef __BASICBODY__
#define __BASICBODY__
#endif
#include "ShipComponent.h"
class BasicBody : public ShipComponent
{
public:
	BasicBody();
	~BasicBody();
	void Damage();
};
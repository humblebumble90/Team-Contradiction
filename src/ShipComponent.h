#pragma once
#ifndef __SHIPCOMPONENT__
#define __SHIPCOMPONENT__
#endif
#include "Frame.h"
class ShipComponent
{
public:
	ShipComponent();
	virtual ~ShipComponent();
protected:
	Frame parent;
};
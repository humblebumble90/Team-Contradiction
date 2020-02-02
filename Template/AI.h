#pragma once
#ifndef __AI__
#define __AI__
#endif
#include "Enemy.h"
class AI {
public:
	AI();
	AI(Enemy parentRef);
	virtual ~AI();
	virtual void PrimaryFunction();
	virtual float GetSpeed(int i);
protected:
	Enemy parent;
	float speed[2] = { 0, 0 };
};
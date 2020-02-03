#pragma once
#ifndef __AI__
#define __AI__
#endif
#include "Enemy.h"
class AI {
public:
	AI();
	virtual ~AI();
	virtual void PrimaryFunction();
	glm::vec2 GetSpeed();
protected:
	Enemy parent;
	glm::vec2 speed;
};
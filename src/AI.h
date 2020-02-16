#pragma once
#ifndef __AI__
#define __AI__
#include "Enemy.h"
class AI {
public:
	AI();
	virtual ~AI();
	virtual void PrimaryFunction();
	virtual glm::vec2 GetSpeed();
	Enemy GetParent();
protected:
	Enemy parent;
	glm::vec2 speed;
};
#endif
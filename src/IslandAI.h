#pragma once
#ifndef __FLYINGISLAND__
#define __FLYINGISLAND__
#include "AI.h"
class IslandAI : public AI {
public:
	IslandAI(glm::vec2 transform);
	~IslandAI();
};
#endif // !__ISLAND__

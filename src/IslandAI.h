#pragma once
#ifndef __FLYINGISLAND__
#define __FLYINGISLAND__
#include "AI.h"
class Island : public AI {
public:
	Island(glm::vec2 transform);
	~Island();
};
#endif // !__ISLAND__

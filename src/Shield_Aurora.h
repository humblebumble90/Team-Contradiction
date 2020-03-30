#pragma once
#include "DisplayObject.h"
#ifndef __SHIELD_AURORA__
#define __SHIELD_AURORA__
class Shield_Aurora:public DisplayObject
{
public:
	Shield_Aurora();
	~Shield_Aurora();
	void draw() override;
	void update() override;
	void clean() override;
private:
};
#endif /*Defined(__SHIELD_AURORA__)*/
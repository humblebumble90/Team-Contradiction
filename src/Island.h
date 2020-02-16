#pragma once
#ifndef __ISLAND__
#define __ISLAND__
#include "DisplayObject.h"

class Island : public DisplayObject
{
public:
	Island();
	~Island();
	
	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__ISLAND__) */
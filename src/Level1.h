#pragma once
#ifndef __LEVEL1__
#define __LEVEL1__

#include "Scene.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
};
#endif 
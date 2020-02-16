#pragma once
#ifndef  __LEVEL1__
#define  __LEVEL1__
#include "LevelScene.h"
#include "Map.h"

class Level1 : public LevelScene
{
public:

	Level1();
	~Level1();

	void draw() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	void update() override;
private:
	Map* m_pMap;
};
#endif /* defined __LEVEL1__ */
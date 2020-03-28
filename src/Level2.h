#pragma once
#ifndef  __LEVEL2__
#define  __LEVEL2__
#include "LevelScene.h"

class Level2 : public LevelScene
{
public:

	Level2();
	~Level2();

	void clean() override;
	void handleEvents() override;
	void start() override;
	void loadAllTextures();
	void loadAllSounds();

private:
};
#endif /* defined __LEVEL1__ */


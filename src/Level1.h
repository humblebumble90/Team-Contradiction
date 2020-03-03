#pragma once
#ifndef  __LEVEL1__
#define  __LEVEL1__
#include "LevelScene.h"

class Level1 : public LevelScene
{
public:

	Level1();
	~Level1();

	void clean() override;
	void handleEvents() override;
	void start() override;
	void loadAllTexture();

private:
};
#endif /* defined __LEVEL1__ */
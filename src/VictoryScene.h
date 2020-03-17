#pragma once
#ifndef __VICTORY_SCENE__
#define __VICTORY_SCENE__
#include "Label.h"
#include "Scene.h"

class VictoryScene : public Scene
{
public:
	VictoryScene();
	~VictoryScene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

private:
	//game objects
	Label* m_pScore;
	Label* m_pHighScore;
};

#endif

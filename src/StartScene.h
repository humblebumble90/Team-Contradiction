#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Start_Scene_Bg.h"
#include "StartButton.h"
#include "Level3Button.h"
#include "explosion.h"

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:

	glm::vec2 m_mousePosition;

	//game objects
	Label* m_pStartLabel;
	Start_Scene_Bg* m_pStart_Scene_Bg;
	StartButton* m_pStartButton;
	Level3Button* m_pLevel3Button;
	Explosion* m_pExplosion;

	
	//methods
	void loadAllSounds();
	void loadAllTextures();
};

#endif /* defined (__START_SCENE__) */
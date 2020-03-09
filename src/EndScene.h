#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Game_Over_Bg.h"
class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	void loadAllSounds();
	Label* m_Label;
	Game_Over_Bg* m_game_over_bg_;
};

#endif /* defined (__END_SCENE__) */
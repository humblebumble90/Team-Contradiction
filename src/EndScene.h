#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Game_Over_Bg.h"
#include "Entry_Bg.h"

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
	void displayEntry();
	void generateEntry();
	void generateEntrylabels();
	
	Label* m_Label;
	Label* m_namingLabel1;
	Label* m_namingLabel2;
	Label* m_namingLabel3;
	
	Game_Over_Bg* m_game_over_bg_;
	Entry_Bg* m_pEntry;

	int entryNum = 0;
	
	bool naming1Done;
	bool naming2Done;
	bool naming3Done;

	std::string entryArr[36] = { "A","B","C","D","E", "F","G", "H", "I","J","K","L","M","N","O","P",
"Q","R","S","T","U","V","W", "X","Y", "Z","0","1","2","3","4","5","6","7","8","9" };

	std::vector<Label*> entryLabels;
	SDL_Color black = { 0,0 ,0, 255 };
};
#endif /* defined (__END_SCENE__) */
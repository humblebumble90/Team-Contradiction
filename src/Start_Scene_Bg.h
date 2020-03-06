#pragma once
#include"DisplayObject.h"
#include "Config.h"
#ifndef __START_SCENE_BG__
#define __START_SCENE_BG__
class Start_Scene_Bg:public DisplayObject
{
public:
	Start_Scene_Bg(std::string imagePath = "../Assets/textures/StartSceneBg.png",
		std::string name = "Start_Scene_Bg",
		GameObjectType type = START_SCENE_BG,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f), bool isCentered = true);
	
	~Start_Scene_Bg();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defiend (__START_SCENE_BG__)*/

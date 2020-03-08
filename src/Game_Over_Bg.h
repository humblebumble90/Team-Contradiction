#pragma once
#include"DisplayObject.h"
#include "Config.h"
#ifndef __GAME_OVER_BG__
#define __GAME_OVER_BG__
class Game_Over_Bg :public DisplayObject
{
public:
	Game_Over_Bg(std::string imagePath = "../Assets/textures/GameOver_Bg.png",
		std::string name = "Game_Over_Bg",
		GameObjectType type = GAME_OVER_BG,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f), bool isCentered = true);

	~Game_Over_Bg();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defined(__GAME_OVER_BG__)*/

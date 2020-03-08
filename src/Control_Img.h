#pragma once
#include "DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>
#ifndef __CONTROL_IMG__
#define __CONTROL_IMG__
class Control_Img :DisplayObject
{
public:
	Control_Img(std::string imagePath = "../Assets/textures/controls.png",
		std::string name = "Control_Img",
		GameObjectType type = CONTROL_IMG,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.99f), bool isCentered = true);

	~Control_Img();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defiend (__CONTROL_IMG__)*/

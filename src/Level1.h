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
	void loadAllTextures();
	void loadAllSounds();

private:
	int second = 60;
	int wave = 4 * second;

	glm::vec2 bottom = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT - 25);
	glm::vec2 middle = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT / 2 + 25);
	glm::vec2 top = glm::vec2(Config::SCREEN_WIDTH + 25, 25);
	glm::vec2 centerTop = glm::vec2(Config::SCREEN_WIDTH + 25, Config::SCREEN_HEIGHT / 4 + 25);
	glm::vec2 centerBottom = glm::vec2(Config::SCREEN_WIDTH + 25, 3 * Config::SCREEN_HEIGHT / 4 - 25);

	glm::vec2 guardianPosition = glm::vec2(Config::SCREEN_WIDTH - 20, Config::SCREEN_HEIGHT / 2);

	glm::vec2 topIslandPosition = glm::vec2(Config::SCREEN_WIDTH + 370, Config::SCREEN_HEIGHT - 50);
	glm::vec2 bottomIslandPosition = glm::vec2(Config::SCREEN_WIDTH + 370, 50);
};
#endif /* defined __LEVEL1__ */
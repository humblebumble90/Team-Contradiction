#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_game_over_bg_->draw();
	m_Label->draw();
}

void EndScene::update()
{
}

void EndScene::clean()
{
	delete m_Label;
	delete m_game_over_bg_;
	removeAllChildren();
}

void EndScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void EndScene::start()
{
	SDL_Color blue = { 255, 0, 0, 255 };
	m_Label = new Label("Push R key to restart the game.", "Dock51", 40, blue, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.9f));
	m_Label->setParent(this);
	addChild(m_Label);

	m_game_over_bg_ = new Game_Over_Bg();
	m_game_over_bg_->setParent(this);
	addChild(m_game_over_bg_);
}

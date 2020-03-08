#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	m_pStart_Scene_Bg->draw();
	m_pStartLabel->draw();
	m_pStartButton->draw();
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
}

void StartScene::clean()
{
	delete m_pStart_Scene_Bg;
	delete m_pStartButton;
	delete m_pStartLabel;
	removeAllChildren();
}

void StartScene::handleEvents()
{
	SDL_Event event;
	int wheel = 0;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				//TheGame::Instance()->changeSceneState(SceneState::LEVEL3_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(END_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

void StartScene::start()
{
	m_pStart_Scene_Bg = new Start_Scene_Bg();
	m_pStart_Scene_Bg->setParent(this);
	addChild(m_pStart_Scene_Bg);
	
	SDL_Color black = { 0, 0, 0, 255 };
	m_pStartLabel = new Label("Guild of Agnis", "Dock51",
		80, black, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.2f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);
	
	m_pStartButton = new StartButton();
	m_pStartButton->setParent(this);
	addChild(m_pStartButton);


	

}

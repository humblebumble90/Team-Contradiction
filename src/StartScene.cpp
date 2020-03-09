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
	m_pLevel3Button->draw();
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pLevel3Button->setMousePosition(m_mousePosition);
	if(m_pStartButton->ButtonClick())
	{
		TheGame::Instance()->changeSceneState(LEVEL1_SCENE);
	}
	if(m_pLevel3Button->ButtonClick())
	{
		TheGame::Instance()->changeSceneState(LEVEL3_SCENE);
	}
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
				m_pLevel3Button->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				m_pLevel3Button->setMouseButtonClicked(true);
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
	loadAllTextures();
	loadAllSounds();
	m_pStart_Scene_Bg = new Start_Scene_Bg();
	addChild(m_pStart_Scene_Bg);
	
	SDL_Color black = { 0, 0, 0, 255 };
	m_pStartLabel = new Label("Guild of Agnis", "Dock51",
		80, black, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.2f));
	addChild(m_pStartLabel);
	
	m_pStartButton = new StartButton();
	addChild(m_pStartButton);
	playSound("Menu", 999);

	m_pLevel3Button = new Level3Button();
	addChild(m_pLevel3Button);

}

void StartScene::loadAllSounds()
{
	std::cout << "Loading sounds" << std::endl;
	loadSound("../Assets/audio/menu.ogg", "Menu", SOUND_MUSIC);
	std::cout << "Finished loading sounds" << std::endl;
}

void StartScene::loadAllTextures()
{
	std::cout << "Loading Textures" << std::endl;
	loadTexture("../Assets/textures/StartSceneBg.png", "Start_Scene_Bg");
	loadTexture("../Assets/textures/Level1.png", "Level1Button");
	loadTexture("../Assets/textures/Level3.png", "Level3Button");
	std::cout << "Finish loading textures" << std::endl;
}

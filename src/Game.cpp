#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include "TileComparators.h"
#include <iomanip>
#include "PlayerShip.h"
#include "LevelScene.h"


Game* Game::s_pInstance = 0;

// Game functions - DO NOT REMOVE ***********************************************

Game::Game() :
	m_pWindow(NULL), m_pRenderer(NULL), m_currentFrame(0), m_currentScene(NULL), m_bRunning(true), m_currentSceneState(SceneState::NO_SCENE), m_frames(0)
{
	srand((unsigned)time(NULL));  // random seed

	
}

Game::~Game()
{
}


bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cout << "SDL Init success" << std::endl;

		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// if window creation successful create our renderer
		if (m_pWindow != 0)
		{
			std::cout << "window creation success" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


			if (m_pRenderer != 0) // render init success
			{
				std::cout << "renderer creation success" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init failure" << std::endl;
				return false; // render int fail
			}

			// IMGUI 
			ImGui::CreateContext();
			ImGuiSDL::Initialize(m_pRenderer, width, height);

			// Initialize Font Support
			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				return false;
			}

			

			//TheTextureManager::Instance()->load("../../Assets/textures/animate-alpha.png", "animate", m_pRenderer);
			start();

		}
		else 
		{
			std::cout << "window init failure" << std::endl;
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init failure" << std::endl;
		return false; //SDL could not intialize
	}

	std::cout << "init success" << std::endl;
	m_bRunning = true; // everything initialized successfully - start the main loop

	return true;
}

void Game::start()
{
	m_currentSceneState = SceneState::NO_SCENE;

	changeSceneState(SceneState::START_SCENE);
}

SDL_Renderer * Game::getRenderer()
{
	return m_pRenderer;
}

glm::vec2 Game::getMousePosition()
{
	return m_mousePosition;
}

void Game::setFrames(Uint32 frames)
{
	m_frames = frames;
}

Uint32 Game::getFrames()
{
	return m_frames;
}

void Game::changeSceneState(SceneState newState)
{
	if (newState != m_currentSceneState) {
		
		if (m_currentSceneState != SceneState::NO_SCENE) 
		{
			m_currentScene->clean();
			std::cout << "cleaning previous scene" << std::endl;
			FontManager::Instance()->clean();
			std::cout << "cleaning FontManager" << std::endl;
			TextureManager::Instance()->clean();
			std::cout << "cleaning TextureManager" << std::endl;
		}

		m_currentSceneState = newState;
		
		switch (m_currentSceneState)
		{
		case SceneState::START_SCENE:
			m_currentScene = new StartScene();
			std::cout << "start scene activated" << std::endl;
			break;
		case SceneState::PLAY_SCENE:
			m_currentScene = new PlayScene();
			std::cout << "play scene activated" << std::endl;
			break;
		case SceneState::END_SCENE:
			m_currentScene = new EndScene();
			std::cout << "end scene activated" << std::endl;
			break;
		default:
			std::cout << "default case activated" << std::endl;
			break;
		}
	}
	
}

void Game::quit()
{
	m_bRunning = false;
}

void Game::destroyEnemy(Enemy* enemy) {
	((LevelScene*)m_currentScene)->DestroyEnemy(enemy);
}

glm::vec2 Game::getPlayerPosition()
{
	return ((LevelScene*)m_currentScene)->getPlayerPosition();
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw colour

	m_currentScene->draw();

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
	m_currentScene->update();
}

void Game::clean()
{
	std::cout << "cleaning game" << std::endl;

	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);

	// Clean Up for ImGui
	ImGui::DestroyContext();

	TTF_Quit();

	SDL_Quit();

	
}
PlayerShip * Game::getPlayerShip()
{
	return m_pPlayerShip;
}

void Game::handleEvents()
{
	m_currentScene->handleEvents();

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) 
			{
				case SDLK_ESCAPE:
					m_bRunning = false;
					break;
				case SDLK_w:
					m_pPlayerShip->setPosition(m_pPlayerShip->getPlayerMaxSpeedY + m_pPlayerShip->getPosition);
					break;
				case SDLK_s:
					m_pPlayerShip->setPosition(m_pPlayerShip->getPlayerMinSpeedY + m_pPlayerShip->getPosition);
					break;
				case SDLK_a:
					m_pPlayerShip->setPosition(m_pPlayerShip->getPlayerminSpeedX + m_pPlayerShip->getPosition);
					break;
				case SDLK_d:
					m_pPlayerShip->setPosition(m_pPlayerShip->getPlayerMaxSpeedX + m_pPlayerShip->getPosition);
					break;
			}
			break;
		default:
			break;
		}
	}
}
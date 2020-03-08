#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include "PlayerShip.h"
#include "LevelScene.h"
#include "AI.h"
#include "Level1.h"
#include "Level3.h"
#include "Weapon.h"


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
		case SceneState::END_SCENE:
			m_currentScene = new EndScene();
			std::cout << "end scene activated" << std::endl;
			break;
		case SceneState::LEVEL1_SCENE:
			m_currentScene = new Level1();
			std::cout << "play scene activated" << std::endl;
			break;
		case SceneState::LEVEL3_SCENE:
			PlayerShip* player = getPlayerShip();
			m_currentScene = new Level3(player);
			std::cout << "boss rush activated" << std::endl;
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

void Game::destroyWeapon(PlayerWeapon* weapon)
{
	((LevelScene*)m_currentScene)->DestroyWeapon(weapon);
}

glm::vec2 Game::getPlayerPosition()
{
	return ((LevelScene*)m_currentScene)->getPlayerPosition();
}

void Game::spawnEnemy(AI* enemyAI)
{
	((LevelScene*)m_currentScene)->spawnEnemy(enemyAI);
}

void Game::spawnPlayerWeapon(PlayerWeapon* pw)
{
	((LevelScene*)m_currentScene)->spawnPlayerWeapon(pw);
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
	m_currentScene->handleEvents();
	for (int z = 0; z < 3; ++z) {
		if (firingCooldown[z] > 0) {
			--firingCooldown[z];
		}
	}
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
	return ((LevelScene*)m_currentScene)->getPlayerShip();
}

void Game::handleEvents()
{
	m_currentScene->handleEvents();
#pragma region Playership control
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A])
	{
		getPlayerShip()->move(LEFT);
	}
	if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
	{
		getPlayerShip()->move(RIGHT);
	}
	if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])
	{
		getPlayerShip()->move(UP);
	}
	if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])
	{
		getPlayerShip()->move(DOWN);
	}
	if (keystates[SDL_SCANCODE_Z])
		if (getPlayerShip()->getPlayerLives() >= 0)
		{
			for (int z = 0; z < 3; ++z) {
				if (firingCooldown[z] == 0) {
					getPlayerShip()->GetFrame()->GetWeapon(z).Fire();
					firingCooldown[z] = firingCooldownReset[z];
				}
			}
		}
	if (keystates[SDL_SCANCODE_X])
		if (getPlayerShip()->getPlayerLives() >= 0)
		{
			if (firingCooldown[0] == 0) {
				getPlayerShip()->GetFrame()->GetWeapon(0).Fire();
				firingCooldown[0] = firingCooldownReset[0];
			}
		}
	if (keystates[SDL_SCANCODE_C])
		if (getPlayerShip()->getPlayerLives() >= 0)
		{
			if (firingCooldown[1] == 0) {
				getPlayerShip()->GetFrame()->GetWeapon(1).Fire();
				firingCooldown[1] = firingCooldownReset[1];
			}
		}
	if (keystates[SDL_SCANCODE_V])
		if (getPlayerShip()->getPlayerLives() >= 0)
		{
			if (firingCooldown[2] == 0) {
				getPlayerShip()->GetFrame()->GetWeapon(2).Fire();
				firingCooldown[2] = firingCooldownReset[2];
			}
		}
#pragma endregion 
	SDL_Event event;
	while  (SDL_PollEvent(&event))
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
			case SDLK_KP_PLUS:
				if(getPlayerShip()->getPlayerSpeed() < 7.5f)
				{
					getPlayerShip()->setPlayerSpeed(0.5f);
				}
				break;
			case SDLK_KP_MINUS:
				if(getPlayerShip()->getPlayerSpeed() > 3.0f)
				{
					getPlayerShip()->setPlayerSpeed(-0.5f);
				}
				break;
				// The below code throws a Debug Assertion Failed Error
			case SDLK_f:
				((Level3*)m_currentScene)->CheatCode(); //WARNING: For testing Level 3 only! Remove this when testing ends!
				//getPlayerShip()->GetFrame().GetWeapon(0).Fire();
				break;
			/*case SDLK_z:
				if (getPlayerShip()->getPlayerLives() >= 0)
				{
					for (int z = 0; z < 3; ++z) {
						if (firingCooldown[z] == 0) {
							getPlayerShip()->GetFrame()->GetWeapon(z).Fire();
							firingCooldown[z] = firingCooldownReset[z];
						}
					}
				}
				break;
			case SDLK_x:
				if (getPlayerShip()->getPlayerLives() >= 0)
				{
									if (firingCooldown[0] == 0) {
					getPlayerShip()->GetFrame()->GetWeapon(0).Fire();
					firingCooldown[0] = firingCooldownReset[0];
					}
				break;
				}

			case SDLK_c:
				if (getPlayerShip()->getPlayerLives() >= 0)
				{
									if (firingCooldown[1] == 0) {
					getPlayerShip()->GetFrame()->GetWeapon(1).Fire();
					firingCooldown[1] = firingCooldownReset[1];
					}
				}
				break;
			case SDLK_v:
				if (getPlayerShip()->getPlayerLives() >= 0)
				{
									if (firingCooldown[2] == 0) {
					getPlayerShip()->GetFrame()->GetWeapon(2).Fire();
					firingCooldown[2] = firingCooldownReset[2];
					}
				}
				break;*/
			}
			break;
		default:
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				getPlayerShip()->setVelocity(glm::vec2(getPlayerShip()->getVelocity().x,0.0f));

				break;
			case SDLK_a:
				getPlayerShip()->setVelocity(glm::vec2(0.0f, getPlayerShip()->getVelocity().y));
				break;
			case SDLK_s:
				getPlayerShip()->setVelocity(glm::vec2(getPlayerShip()->getVelocity().x, 0.0f));
				break;
			case SDLK_d:
				getPlayerShip()->setVelocity(glm::vec2(0.0f, getPlayerShip()->getVelocity().y));
				break;
			case SDLK_UP:
				getPlayerShip()->setVelocity(glm::vec2(getPlayerShip()->getVelocity().x, 0.0f));

				break;
			case SDLK_LEFT:
				getPlayerShip()->setVelocity(glm::vec2(0.0f, getPlayerShip()->getVelocity().y));
				break;
			case SDLK_DOWN:
				getPlayerShip()->setVelocity(glm::vec2(getPlayerShip()->getVelocity().x, 0.0f));
				break;
			case SDLK_RIGHT:
				getPlayerShip()->setVelocity(glm::vec2(0.0f, getPlayerShip()->getVelocity().y));
				break;
			default:
				break;
			}
		}
	}
}
#pragma once
#ifndef __Game__
#define __Game__

// Core Libraries
#include <iostream>
#include <vector>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// IMGUI Includes
#include "IMGUI/imgui.h"
#include "IMGUI_SDL/imgui_sdl.h"

// Game Managers
#include "Config.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "Util.h"

// Scenes
#include "StartScene.h"
#include "PlayScene.h"
#include "EndScene.h"

//Game Objects
#include "PlayerShip.h"
#include "Enemy.h"
#include "PlayerWeapon.h"

class Game
{
public:
	friend class AI;

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}

	// simply set the running variable to true
	void init() { m_bRunning = true; }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	// public functions
	void render();
	void update();
	void handleEvents();
	void clean();

	PlayerShip* getPlayerShip();
	void updateLabels();

	// a function to access the private running variable
	bool running() { return m_bRunning; }

	// getters
	SDL_Renderer* getRenderer();
	glm::vec2 getMousePosition();

	void setFrames(Uint32 frames);
	Uint32 getFrames();

	void changeSceneState(SceneState newState);
	void quit();

	void destroyEnemy(Enemy* enemy);
	void destroyWeapon(PlayerWeapon* weapon);
	glm::vec2 getPlayerPosition();
	void spawnEnemy(AI* enemyAI);
	void spawnPlayerWeapon(PlayerWeapon* pw);
	void spawnExplosion(glm::vec2 position);


	int guild = 0;
	void setGuild(int num);
	int getGuild();
	Scene* getCurrentSceneState();

	Scene* getScene();

	//Continue feature
	int Continue(), ContinueStack(), ContinueScore();
	void resetContinues(), increaseContinue(int i), increaseStack(int i);

private:
	Game();
	~Game();

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	bool m_bRunning;

	static Game* s_pInstance;
	
	void start();

	glm::vec2 m_mousePosition;

	Uint32 m_frames;

	Scene* m_currentScene;
	SceneState m_currentSceneState;

	int firingCooldown[3] = { 0,0,0 };
	int firingCooldownReset[3] = { 20,20,20 };

	//Continue feature
	int continiue = 0, continueStack = 0, continueScore = 6000;
};

typedef Game TheGame;

#endif /* defined (__Game__) */
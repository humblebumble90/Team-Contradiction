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

class Game
{
public:
	

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

	// a function to access the private running variable
	bool running() { return m_bRunning; }

	// getters
	SDL_Renderer* getRenderer();
	glm::vec2 getMousePosition();

	void setFrames(Uint32 frames);
	Uint32 getFrames();

	void changeSceneState(SceneState newState);
	void quit();

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
};

typedef Game TheGame;

#endif /* defined (__Game__) */

/*
Josh's Frame Sketchboard:

W = Generic Weapon
F = Flamethrower
C = Cannon
M = Missile
B = Body
I = Indestructible Body
E = Blank (Empty)

Player:
B	B	W	E
B	B	B	W
B	B	W	E

Enemy 1:
B

Enemy 2:
B	B	B
M	B	B
B	B	B

Enemy 3:

Enemy 4:

Enemy 5:

Enemy 6:

Boss 1:

Boss 2 (Multistage):

NOTE: All Level 3 bosses use identical size-scaling
Level 3 Boss 1: Blaster Skiff
E	M	M	I	E	E	E	E
E	M	M	I	E	E	E	E
E	M	M	I	I	E	E	E
E	M	M	I	I	E	E	E
E	M	M	I	I	I	E	E
E	M	M	I	I	I	E	E
E	M	M	I	I	I	I	E
B	I	I	I	I	I	I	I
B	I	I	I	I	I	I	I
E	M	M	I	I	I	E	E
E	M	M	I	I	I	I	E
E	M	M	I	I	E	E	E
E	M	M	I	I	E	E	E
E	M	M	I	E	E	E	E
E	M	M	I	E	E	E	E

Level 3 Boss 2: Firebrand
M	F	F	F	F	F	E	E
M	B	B	B	B	B	B	E
F	B	B	B	B	B	B	E
C	B	B	B	B	B	B	E
C	B	B	B	B	B	B	B
C	B	B	B	B	B	B	B
C	B	B	B	B	B	B	B
C	B	B	B	B	B	B	B
C	B	B	B	B	B	B	E
F	B	B	B	B	B	B	E
M	B	B	B	B	B	B	E
M	F	F	F	F	F	E	E

Level 3 Boss 3: Triple Barge
E	W	W	W	W	E
W	B	B	B	B	W
W	B	B	B	B	W
W	B	B	B	B	W
W	B	B	B	B	W
E	W	W	W	W	E

Level 3 Boss 4: Cannonlord
E	C	B	B	C	B	B	C	E
C	B	B	B	B	B	B	B	C
B	B	B	B	B	B	B	B	B
B	B	B	B	B	B	B	B	B
C	B	B	B	B	B	B	B	C
E	C	B	B	C	B	B	C	E

Level 3 Boss 5 (Final Boss): Deathcage
NOTE: Deathcage is as tall as the screen
NOTE 2: Deathcage's body expands off to the right, but since that part of its body is unhittable, its frame is remaining this size to save on memory
I	B	B	B	B	B	B	B	B	B	B	B	B	B	I	E	I
M	C	C	M	C	C	M	C	C	M	C	C	M	C	B	I	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	M	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	M	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	M	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	M	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
E	E	E	E	E	E	E	E	E	E	E	E	E	E	C	B	I
M	C	C	M	C	C	M	C	C	M	C	C	M	C	B	I	I
I	B	B	B	B	B	B	B	B	B	B	B	B	B	I	E	I

*/
#pragma once
#include "PlayerShip.h"
#include "Game.h"
#include <iostream>
#include "Frame.h"
#include "LevelScene.h"
#include "BasicBody.h"
#include "MissileLauncher.h"
#include "Blank.h"

PlayerShip::PlayerShip(int playerHealth, int playerLives, glm::vec2 targetTransform) :m_isMoving(false), m_maxSpeed(5.0f), m_alpha(255)
{
	TheTextureManager::Instance()->load("../Assets/textures/player.png", "player", TheGame::Instance()->getRenderer());
	setPosition(targetTransform);
	setIsColliding(false);
	setType(GameObjectType::PLAYER);

	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		BasicBody(),BasicBody(),MissileLauncher(),Blank(),
		BasicBody(),BasicBody(),BasicBody(),MissileLauncher(),
		BasicBody(),BasicBody(),MissileLauncher(),Blank()
	};
#pragma endregion
	frame = Frame(5, //Enemy is 300px by 300px
		build, 15, 10); //Will tweak if it proves to be too much or too little
	frame.Initialize(this);
	name = "Player";
	std::cout << "PlayerShip is instantiated!" << std::endl;
}

PlayerShip::~PlayerShip()
{
	;
}

void PlayerShip::Damage(int i)
{
	if (playerHealth >= 1)
	{
		if (playerLives <= 0)
		{
			Game::Instance()->changeSceneState(END_SCENE);
		}
		else

		{
			this->playerHealth -= i;
			playerLives -= 1;
			playerHealth += 1;
			invincible();
		}
	}
}
bool PlayerShip::getInvincibility()
{
	return inv;
}
void PlayerShip::invincible()
{
	this->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.2f, Config::SCREEN_HEIGHT * 0.5f));
	inv = true;
	TextureManager::Instance()->setAlpha("player", m_alpha * 0.5);
	endInvincibleTime = SDL_GetTicks() + 3000; // 3 seconds

}


Frame PlayerShip::GetFrame()
{
	return frame;
}
void PlayerShip::draw()
{
	TheTextureManager::Instance()->draw
	("player", getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(),0,255, true);
}

void PlayerShip::move(Move newMove)
{
	if (m_isMoving)
	{
		switch (newMove)
		{
		case RIGHT:
			setVelocity(glm::vec2(1.0f * m_maxSpeed, getVelocity().y));
			break;
		case LEFT:
			setVelocity(glm::vec2(-1.0f * m_maxSpeed, getVelocity().y));
			break;
		case UP:
			setVelocity(glm::vec2(getVelocity().x, -1.0f * m_maxSpeed));
			break;
		case DOWN:
			setVelocity(glm::vec2(getVelocity().x, 1.0f * m_maxSpeed));
			break;
		}
	}
}

bool PlayerShip::getIsMoving()
{
	return m_isMoving;
}

void PlayerShip::setIsMoving(bool newState)
{
	m_isMoving = newState;
}


void PlayerShip::update()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	if (m_isMoving == false)
	{
		if (currentVelocity.x < 0)
		{
			currentVelocity.x *= 0.95f;
		}
		else if (currentVelocity.x > 0)
		{
			currentVelocity.x *= 0.95f;
		}
		if (currentVelocity.y < 0)
		{
			currentVelocity.y *= 0.95f;
		}
		else if (currentVelocity.y >= 0)
		{
			currentVelocity.y *= 0.95f;
		}
	}

	setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));


	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;
	setPosition(glm::vec2(deltax, deltay));
	
	if (inv == true && endInvincibleTime <= SDL_GetTicks())
	{
		inv = false;
		TextureManager::Instance()->setAlpha("player", m_alpha);
	}
	
}

void PlayerShip::clean()
{
	Damage(1);
}



#pragma once
#include "PlayerShip.h"
#include "Game.h"
#include <iostream>
#include "Frame.h"

PlayerShip::PlayerShip(Frame playerFrame, int playerHealth, int playerLives, glm::vec2 targetTransform)
{
	TheTextureManager::Instance()->load("../Assets/textures/player.png", "player", TheGame::Instance()->getRenderer());
	setPosition(targetTransform);
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	frame = playerFrame;
	frame.Initialize(this);
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
			m_pLevelScene->GameOver();
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
	endInvincibleTime = SDL_GetTicks() + 3000; // 3 seconds

}


Frame PlayerShip::GetFrame()
{
	return frame;
}

glm::vec2 PlayerShip::getPlayerMaxSpeedX()
{
	return maxSpeedX = glm::vec2(2.0f, 0);
}

glm::vec2 PlayerShip::getPlayerminSpeedX()
{
	return minSpeedX = glm::vec2(-2.0f, 0);
}

glm::vec2 PlayerShip::getPlayerMaxSpeedY()
{
	return maxSpeedY = glm::vec2(0, -2.0f);
}

glm::vec2 PlayerShip::getPlayerMinSpeedY()
{
	return minSpeedY = glm::vec2(0, 2.0f);
}

void PlayerShip::draw()
{
	TheTextureManager::Instance()->draw
	("player", getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(), true);
}

void PlayerShip::update()
{
	if (inv == true && endInvincibleTime <= SDL_GetTicks())
	{
		inv = false;
	}
}

void PlayerShip::clean()
{
	Damage(1);
}




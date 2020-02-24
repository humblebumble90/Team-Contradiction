#pragma once
#include "PlayerShip.h"
#include "Game.h"
#include <iostream>
#include "Frame.h"
#include "LevelScene.h"
#include "BasicBody.h"
#include "MissileLauncher.h"
#include "Blank.h"
#include <functional>

PlayerShip::PlayerShip(int playerHealth, int playerLives, glm::vec2 targetTransform)
:m_isMoving(false), m_maxSpeed(5.0f), m_alpha(255),name("Player"),inv(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/player.png", "Player", TheGame::Instance()->getRenderer());
	glm::vec2 size = TextureManager::Instance()->getTextureSize("Player");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(targetTransform);
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	m_playerHealth = playerHealth;
	m_playerLives = playerLives;

	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		BasicBody(),BasicBody(),MissileLauncher(),Blank(),
		BasicBody(),BasicBody(),BasicBody(),MissileLauncher(),
		BasicBody(),BasicBody(),MissileLauncher(),Blank()
	};
#pragma endregion
	frame = new Frame(5, //Enemy is 300px by 300px
		build, 15, 10); //Will tweak if it proves to be too much or too little
	frame->Initialize(this);
	std::cout << "PlayerHealth: " << m_playerHealth << std::endl;
	std::cout << "Player Lives: " << m_playerLives << std::endl;
	std::cout << "PlayerShip is instantiated!" << std::endl;
	std::cout <<"Player:s memory address: "<< this << std::endl;
	std::cout << "Frame's memory address: " << frame << std::endl;
	std::cout << "frame's parent(Player): " << frame->getParent() << std::endl;
	std::cout << "The first element's name: " << frame->GetBuild().begin()->getName() << std::endl;
	std::cout << "The element's parent(Player's frame): " << frame->GetBuild().begin()->getParent() << std::endl;
	std::cout << "The first element's parent's parent(should be player): "<< frame->GetBuild().begin()->getParent()->getParent() << std::endl;
}

PlayerShip::~PlayerShip()
{
	;
}

void PlayerShip::Damage(int i)
{
	if (m_playerHealth >= 1 && m_playerLives > 0)
	{
		invincible();
		m_playerHealth -= i;
		//std::cout << "Player damaged!\n";
		//std::cout << "PlayerHealth: " << m_playerHealth << std::endl;
		m_playerLives -= 1;
		//std::cout << "Player life decreases for 1\n!";
		//std::cout << "Player life : "<< m_playerLives << std::endl;
		m_playerHealth += 1;
		//std::cout << "Player health restored by a decreased life: " << m_playerHealth << std::endl;
	}
		else if(m_playerLives <= 0)
		{
			//std::cout << "Player Health: " << m_playerHealth << std::endl;
			//std::cout << "Player Lives: " << m_playerLives << std::endl;
			//std::cout << "Player died!" << std::endl;
			//Game::Instance()->changeSceneState(END_SCENE);
		}
}
bool PlayerShip::getInvincibility()
{
	return inv;
}
void PlayerShip::invincible()
{
	inv = true;
	std::cout << "Invincibled!\n";
	m_alpha *= 0.5f;
	endInvincibleTime = SDL_GetTicks() + 3000; // 3 seconds

}


Frame* PlayerShip::GetFrame()
{
	return frame;
}
void PlayerShip::draw()
{
	TheTextureManager::Instance()->draw
	("Player", getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(),0,m_alpha, true);
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

void PlayerShip::m_checkBounds()
{
	// check right bounds
	if (getPosition().x >= Config::SCREEN_WIDTH - getWidth() * 0.5f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH - getWidth() * 0.5f, getPosition().y));
	}

	// check left bounds
	if (getPosition().x <= getWidth() * 0.5f)
	{
		setPosition(glm::vec2(getWidth() * 0.5f, getPosition().y));
	}

	// check top bounds
	if (getPosition().y >= Config::SCREEN_HEIGHT - getHeight() * 0.5f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT - getHeight() * 0.5f));
	}

	// check bottom bounds
	if (getPosition().y <= getHeight() * 0.5f)
	{
		setPosition(glm::vec2(getPosition().x, getHeight() * 0.5f));
	}

}


void PlayerShip::update()
{
	m_checkBounds();
	
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
		std::cout << "invincible finished!\n";
		inv = false;
		m_alpha = 255;
	}
	
}

void PlayerShip::clean()
{
}



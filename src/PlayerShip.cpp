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

PlayerShip::PlayerShip(int health, int lives, glm::vec2 targetTransform)
:m_isMoving(false), m_maxSpeed(5.0f), m_alpha(255),name("Player"),inv(false)
{
	changeTexture("Player");
	setPosition(targetTransform);
	setIsColliding(false);
	setType(GameObjectType::PLAYER);

	std::vector<ShipComponent> build =
#pragma region Frame Construction
	{
		/*Blank(), Blank(),Blank(),Blank(),Blank(),Blank(),Blank(),Blank(),BasicBody(), Blank(),Blank(),Blank(),Blank(),Blank(),Blank(),
		BasicBody(), Blank(),Blank(),Blank(),Blank(),Blank(),Blank(),Blank(),BasicBody(),Blank(),Blank(),Blank(),Blank(),Blank(),Blank(),
		BasicBody(), BasicBody(), Blank(),Blank(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),MissileLauncher(),Blank(),Blank(),
		BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),Blank(),
		BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),MissileLauncher(),
		Blank(), BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),
		Blank(),Blank(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),Blank(),
		Blank(),Blank(),Blank(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),MissileLauncher(),Blank(),Blank(),
		Blank(),Blank(),Blank(),Blank(),Blank(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),Blank(),Blank(),Blank(),Blank(),Blank(),
		Blank(),Blank(),Blank(),Blank(),Blank(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),BasicBody(),Blank(),Blank(),Blank(),Blank(),Blank()*/
		BasicBody(),BasicBody(),BasicBody(),MissileLauncher(),
		BasicBody(), BasicBody(),BasicBody(), MissileLauncher(),
		BasicBody(), BasicBody(), BasicBody(), MissileLauncher()
	};
#pragma endregion
	frame = new Frame(37.5, //Enemy is 150px by 100px
		build, 4, 3); //Will tweak if it proves to be too much or too little
	frame->Initialize(this);
	playerLives = lives;
	playerHealth = health;
	std::cout << "PlayerHealth: " << playerHealth << std::endl;
	std::cout << "Player Lives: " << playerLives << std::endl;
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
	
}

void PlayerShip::Damage(int i)
{
	if (playerHealth >= 1 && playerLives >= 0)
	{
		playerHealth -= i;
		std::cout << "Player damaged!\n";
		std::cout << "PlayerHealth: " << playerHealth << std::endl;
		//playerLives -= 1;
		std::cout << "Player life decreases for 1!" << std::endl;
		playerHealth += 1;
		std::cout << "Player life restored by a decreased life: " << playerHealth << std::endl;
		invincible();
	}
	else if(playerLives <= 0)
	{
		std::cout << "Player Health: " << playerHealth << std::endl;
		std::cout << "Player Lives: " << playerLives << std::endl;
		std::cout << "Player died!" << std::endl;
		//Game::Instance()->changeSceneState(END_SCENE);
	}
}
bool PlayerShip::getInvincibility()
{
	return inv;
}

void PlayerShip::invincible()
{
	//if not invincible do this
	if (!inv)
	{
		std::cout << "Invincibled!\n";
		inv = true;
		m_alpha *= 0.5f;
		endInvincibleTime = SDL_GetTicks() + 3000; // 3 seconds
	}
}

void PlayerShip::checkBound()
{
	if(getPosition().x <= Config::SCREEN_WIDTH * 0.05f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.05f, getPosition().y));
	}
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.95f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.95f, getPosition().y));
	}
	if(getPosition().y <= Config::SCREEN_HEIGHT * 0.05f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.05f));
	}
	if (getPosition().y >= Config::SCREEN_HEIGHT * 0.95f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.95f));
	}
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

bool PlayerShip::getIsMoving()
{
	return m_isMoving;
}

void PlayerShip::setIsMoving(bool newState)
{
	m_isMoving = newState;
}

int PlayerShip::getPlayerLives()
{
	return playerLives;
}

void PlayerShip::setPlayerLives(int num)
{
	playerLives += num;
}

int PlayerShip::getPlayerScore()
{
	return playerScore;
}

void PlayerShip::setPlayerScore(int num)
{
	playerScore += num;
}

float PlayerShip::getPlayerSpeed()
{
	return m_maxSpeed;
}

void PlayerShip::setPlayerSpeed(float num)
{
	m_maxSpeed += num;
}

void PlayerShip::update()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	if (m_isMoving == false)
	{
		currentVelocity.x *= 0.99f;
		currentVelocity.y *= 0.99f;
	}

	if (playerLives >= 0)
	{
		setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
		auto deltax = currentPosition.x + currentVelocity.x;
		auto deltay = currentPosition.y + currentVelocity.y;
		setPosition(glm::vec2(deltax, deltay));
	}
	else
	{
		delete this;
	}
	
	//when the invincibility has finished run this
	if (inv == true && endInvincibleTime <= SDL_GetTicks())
	{
		std::cout << "invincible finished!\n";
		inv = false;
		m_alpha = defaultAlpha;
	}
	checkBound();
}

void PlayerShip::clean()
{
}



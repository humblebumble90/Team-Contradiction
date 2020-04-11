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
#include <glm/detail/type_vec2.hpp>
#include "Scoreboard.h"

PlayerShip::PlayerShip(int health, int lives, glm::vec2 targetTransform)
:m_isMoving(false), m_maxSpeed(5.0f), m_alpha(255),name("Player"),
inv(false),killCounter(0),shieldAvailable(false),continiue(0),continueStack(0),
dead(false), continueScore(6000)
{
	changeTexture("Player");
	//changeTexture("Player");
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
		BasicBody(),BasicBody(),MissileLauncher(),
		BasicBody(),BasicBody(), MissileLauncher(),
		BasicBody(), BasicBody(), MissileLauncher()
	};
#pragma endregion
	frame = new Frame(30, //Player Collider is 90px by 90px
		build, 3, 3);
	frame->Initialize(this);
	playerLives = lives;
	playerHealth = health;
	//SDL_SetTextureColorMod(TextureManager::Instance()->getTexture("Player"), 255, 255, 255);
	//SDL_SetTextureColorMod(TextureManager::Instance()->getTexture("Player"), 255, 51, 100);
	//std::cout << "PlayerHealth: " << playerHealth << std::endl;
	//std::cout << "Player Lives: " << playerLives << std::endl;
	//std::cout << "PlayerShip is instantiated!" << std::endl;
	//std::cout <<"Player:s memory address: "<< this << std::endl;
	//std::cout << "Frame's memory address: " << frame << std::endl;
	//std::cout << "frame's parent(Player): " << frame->getParent() << std::endl;
	//std::cout << "The first element's name: " << frame->GetBuild().begin()->getName() << std::endl;
	//std::cout << "The element's parent(Player's frame): " << frame->GetBuild().begin()->getParent() << std::endl;
	//std::cout << "The first element's parent's parent(should be player): "<< frame->GetBuild().begin()->getParent()->getParent() << std::endl;
}

PlayerShip::~PlayerShip()
{
	
}

void PlayerShip::Damage(int i)
{
	if(playerLives >= 0 && playerHealth == 1 && !inv)
	{
		if(shieldAvailable && getPlayerLives() == 0)
		{
			invincible();
			shieldAvailable = false;
		}
		else
		{
			//std::cout << "Player damaged!\n";
			playerHealth -= 1;
			//std::cout << "PlayerHealth: " << playerHealth << std::endl;
			playerLives -= 1;
			//std::cout << "Player life decreases for 1!" << std::endl;
			playerHealth += 1;
			//std::cout << "Player life restored by a decreased life: " << playerHealth << std::endl;
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
	if(getPosition().x <= Config::SCREEN_WIDTH * 0.03f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.03f, getPosition().y));
	}
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.97f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.97f, getPosition().y));
	}
	if(getPosition().y <= Config::SCREEN_HEIGHT * 0.03f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.03f));
	}
	if (getPosition().y >= Config::SCREEN_HEIGHT * 0.97f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.97f));
	}
}

int PlayerShip::getKillCounter()
{
	return killCounter;
}

void PlayerShip::setKillCounter(int num)
{
		killCounter += num;
		//std::cout << killCounter << std::endl;
}

bool PlayerShip::getShieldAvailable()
{
	return shieldAvailable;
}

void PlayerShip::setShieldAvailable(bool newState)
{
	shieldAvailable = newState;
}

void PlayerShip::initializeKillCounter()
{
	killCounter = 0;
}

int PlayerShip::getContinueChance()
{
	return continiue;
}

void PlayerShip::setContinueChance(int num)
{
	continiue += num;
}

bool PlayerShip::getPlayerDead()
{
	return dead;
}

void PlayerShip::setPlayerDead(bool newState)
{
	dead = newState;
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
	playerLives = num;
}

void PlayerShip::adjustPlayerLives(int num)
{
	playerLives += num;
	Scoreboard::Instance()->setLives(playerLives);
}

int PlayerShip::getScore()
{
	return playerScore;
}

void PlayerShip::addScore(int num)
{
	playerScore += num;
	Scoreboard::Instance()->setScore(playerScore);
	if(playerScore >= continueScore + (continueScore *continueStack))
	{
		continiue += 1;
		continueStack += 1;
		std::cout << "continue increased\n";
		std::cout <<"Continue: " << continiue << std::endl;
		TheGame::Instance()->updateLabels();
	}
}

float PlayerShip::getPlayerSpeed()
{
	return m_maxSpeed;
}

void PlayerShip::setPlayerSpeed(float num)
{
	m_maxSpeed = num;
}

void PlayerShip::update()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	//if (m_isMoving == false)
	//{
	//	currentVelocity.x *= 0.9f;
	//	currentVelocity.y *= 0.9f;
	//}
	if (playerLives >= 0)
	{
		setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
		auto deltax = currentPosition.x + currentVelocity.x;
		auto deltay = currentPosition.y + currentVelocity.y;
		setPosition(glm::vec2(deltax, deltay));
	}
	
	//when the invincibility has finished run this
	if (inv == true && endInvincibleTime <= SDL_GetTicks())
	{
		//std::cout << "invincible finished!\n";
		inv = false;
		m_alpha = defaultAlpha;
	}
	checkBound();
}

void PlayerShip::clean()
{
}



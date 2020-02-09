#pragma once
#include "PlayerShip.h"
#include "Game.h"

PlayerShip::PlayerShip()
{
	TheTextureManager::Instance()->load("../Assets/textures/plane.png", "player", TheGame::Instance()->getRenderer());
	setPosition(glm::vec2(0, 430.0f));
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
}
PlayerShip::~PlayerShip()
{
	;
}

void PlayerShip::Start()
{
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
}

void PlayerShip::clean()
{
}

void PlayerShip::Damage(int i)
{
}




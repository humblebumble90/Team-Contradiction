#include "Shield_Aurora.h"
#include "TextureManager.h"
#include "Game.h"

Shield_Aurora::Shield_Aurora()
{
	changeTexture("shield_aurora");
	auto size = TheTextureManager::Instance()->getTextureSize("shield_aurora");
	setWidth(size.x);
	setHeight(size.y);
}

Shield_Aurora::~Shield_Aurora()
{
	delete this;
}

void Shield_Aurora::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TextureManager::Instance()->draw("shield_aurora", xComponent, yComponent, Game::Instance()->getRenderer());
}

void Shield_Aurora::update()
{
	setPosition(glm::vec2(Game::Instance()->getPlayerShip()->getPosition().x - 50.0f, 
		Game::Instance()->getPlayerShip()->getPosition().y - 50.0f));
}

void Shield_Aurora::clean()
{
}

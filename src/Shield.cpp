#include "Shield.h"
#include "TextureManager.h"
#include "Game.h"

Shield::Shield():collided(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/Shield.png",
		"Shield", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Shield");
	setWidth(size.x);
	setHeight(size.y);
	setIsColliding(false);
	setType(GameObjectType::SHIELD);
	setVelocity(glm::vec2(5.0f, 0.0f));
}

Shield::~Shield()
{
}

void Shield::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("Shield", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Shield::update()
{
	setPosition(glm::vec2(getPosition().x + getVelocity().x, 0.0f));
}

void Shield::clean()
{
}

bool Shield::getCollided()
{
	return collided;
}

void Shield::setCollided(bool newState)
{
	collided = newState;
	delete this;
}

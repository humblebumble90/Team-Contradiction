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
	setVelocity(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::SHIELD);
}

Shield::~Shield()
{
	TheTextureManager::Instance()->removeTexture("Shield");
}

void Shield::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("Shield", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Shield::move()
{
	setPosition(glm::vec2(getPosition().x + getVelocity().x, getPosition().y + getVelocity().y));
		
}

void Shield::update()
{
	move();
	if(this->getPosition().x < 0)
	{
		this->setCollided(true);
	}
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

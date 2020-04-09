#include "Shield.h"
#include "TextureManager.h"
#include "Game.h"

Shield::Shield(std::string id) :collided(false), ID("")
{
	ID = id;
	TheTextureManager::Instance()->load("../Assets/textures/Shield.png",
		ID, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(ID);
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::SHIELD);
}

Shield::~Shield()
{
	delete this;;
}

void Shield::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(ID, xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Shield::move()
{
	setPosition(glm::vec2(getPosition().x + getVelocity().x, getPosition().y + getVelocity().y));
		
}

void Shield::update()
{
	move();
}

void Shield::clean()
{
	TextureManager::Instance()->removeTexture(ID);
}

//bool Shield::getCollided()
//{
//	return collided;
//}
//
//void Shield::setCollided(bool newState)
//{
//	collided = newState;
//}

std::string Shield::getID()
{
	return ID;
}

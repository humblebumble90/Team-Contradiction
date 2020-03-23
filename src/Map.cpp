#include "Map.h"
#include "Game.h"

Map::Map()
{
	changeTexture("map");
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("map");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(-5, 0));
	_reset();
	setIsColliding(false);
	setType(GameObjectType::OCEAN);
}

Map::~Map()
{
}

void Map::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(name, xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Map::update()
{
	_move();
	_checkBounds();
}

void Map::clean()
{
}

void Map::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Map::_checkBounds()
{
	if (getPosition().x <= -1950)
	{
		_reset();
	}
}

void Map::_reset()
{
	setPosition(glm::vec2(1960, 0));
}

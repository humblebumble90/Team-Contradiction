#include "Power_Up.h"
#include "TextureManager.h"
#include "Game.h"

Power_Up::Power_Up(PlayerWeaponType weaponType) :collided(false), weapon(weaponType)
{
	TheTextureManager::Instance()->load("../Assets/textures/Agnium.png",
		"Agnium", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Agnium");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.5f));
	setVelocity(glm::vec2(-5.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::POWER_UP);
}

Power_Up::~Power_Up()
{
}

void Power_Up::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("Agnium", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}
void Power_Up::move()
{
	setPosition(glm::vec2(getPosition().x + getVelocity().x, getPosition().y + getVelocity().y));

}

void Power_Up::update()
{
	move();
}

void Power_Up::clean()
{
}

bool Power_Up::getCollided()
{
	return collided;
}

void Power_Up::setCollided(bool newState)
{
	collided = newState;
	delete this;
}

PlayerWeaponType Power_Up::getWeaponType()
{
	return weapon;
}

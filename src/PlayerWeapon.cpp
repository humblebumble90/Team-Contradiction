#include "PlayerWeapon.h"
#include "Game.h"

PlayerWeapon::PlayerWeapon()
{
	//DANGER! Don't use!
}

PlayerWeapon::~PlayerWeapon()
{
}

void PlayerWeapon::draw()
{
	int xComponent = getPosition().x - (frame->getGridSize() * frame->GridWidth() / 2);
	int yComponent = getPosition().y - (frame->getGridSize() * frame->GridHeight() / 2);

	TheTextureManager::Instance()->draw(name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void PlayerWeapon::update()
{
}

void PlayerWeapon::clean()
{
}

void PlayerWeapon::Move()
{
	setPosition(glm::vec2(getPosition() + speed.x, getPosition() + speed.y));
}

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
	TheTextureManager::Instance()->draw(name, getPosition().x - (frame->getGridSize() * frame->GridWidth() / 2), getPosition().y - (frame->getGridSize() * frame->GridHeight() / 2),
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
	setPosition(glm::vec2(getPosition().x + speed.x, getPosition().y + speed.y));
}

Frame* PlayerWeapon::getFrame()
{
	return frame;
}
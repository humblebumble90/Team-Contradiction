#include "PlayerWeapon.h"
#include "Game.h"

PlayerWeapon::PlayerWeapon()
{
	//DANGER! Don't use!
}

PlayerWeapon::~PlayerWeapon()
{
}

void PlayerWeapon::start()
{
	auto size = TheTextureManager::Instance()->getTextureSize(name);
	setWidth(size.x);
	setHeight(size.y);
}


void PlayerWeapon::draw()
{
	TheTextureManager::Instance()->draw(name, getPosition().x, getPosition().y,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void PlayerWeapon::update()
{
	Move();

}

void PlayerWeapon::clean()
{
}

void PlayerWeapon::Move()
{

	
	setPosition(glm::vec2(getPosition().x + speed.x, getPosition().y + speed.y));
	if (getPosition().x + ((frame->GridWidth() * getFrame()->getGridSize()) / 2) > Config::SCREEN_WIDTH) {
		TheGame::Instance()->destroyWeapon(this);
	}
}

Frame* PlayerWeapon::getFrame()
{
	return frame;
}

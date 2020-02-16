#include "WeaponMissile.h"
#include "Game.h"

WeaponMissile::WeaponMissile()
{

}

WeaponMissile::~WeaponMissile()
{
}

void WeaponMissile::draw()
{
	/*TheTextureManager::Instance()->load(weaponPath, weaponName, TheGame::Instance()->getRenderer());
	SetSpeed(250.0f);

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(weaponName);
	setWidth(size.x);
	setHeight(size.y);*/
}

void WeaponMissile::update()
{
}

void WeaponMissile::clean()
{
}

float WeaponMissile::GetSpeed()
{
	return m_velocity;
}

void WeaponMissile::SetSpeed(float speed)
{
	m_velocity = speed;
}

void WeaponMissile::Move()
{
	setVelocity(glm::vec2(70.0f * GetSpeed(), 0.0f));
}

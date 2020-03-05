#include "WeaponMissile.h"
#include "Game.h"

WeaponMissile::WeaponMissile()
{
	
	changeTexture("ship3");
	setPosition(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::WEAPON_MISSILE);
	setVelocity(glm::vec2(0.0f, 0.0f));
	SetSpeed(50.0f);
}

WeaponMissile::~WeaponMissile()
{
}

void WeaponMissile::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
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
	setVelocity(glm::vec2(1.0f * GetSpeed(), 0.0f));
}

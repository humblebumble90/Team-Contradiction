#include "WeaponMissile.h"
#include "Game.h"

WeaponMissile::WeaponMissile(glm::vec2 position, glm::vec2 velocity)
{
	name = "Missile";
	TheTextureManager::Instance()->load("../Assets/textures/missile.png", name, TheGame::Instance()->getRenderer());
	
	/*glm::vec2 size = TheTextureManager::Instance()->getTextureSize(name);

	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::WEAPON_MISSILE);
	setVelocity(glm::vec2(0.0f, 0.0f));
	SetSpeed(50.0f);*/
}

WeaponMissile::~WeaponMissile()
{
}

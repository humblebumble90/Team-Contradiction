#include "WeaponMissile.h"
#include "Game.h"
#include "IndesBody.h"

WeaponMissile::WeaponMissile(glm::vec2 position, glm::vec2 velocity)
{
	name = "Missile";
	TheTextureManager::Instance()->load("../Assets/textures/Missile.png", name, TheGame::Instance()->getRenderer());
	std::vector<ShipComponent> build = { IndesBody(true) };
	frame = new Frame(10, build, 1, 1); //Missile is 10px by 10px
	frame->Initialize(this);
	setPosition(position);
	speed = velocity;
}
	/*glm::vec2 size = TheTextureManager::Instance()->getTextureSize(name);*/


WeaponMissile::~WeaponMissile()
{

}

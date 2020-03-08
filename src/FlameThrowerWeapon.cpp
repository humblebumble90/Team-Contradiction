#include "FlameThrowerWeapon.h"
#include "Game.h"
#include "IndesBody.h"

FlameThrowerWeapon::FlameThrowerWeapon(glm::vec2 position)
{
	TheTextureManager::Instance()->load("../Assets/textures/Flamethrower.png", "Flamethrower", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Flamethrower");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);

	std::vector<ShipComponent> build = { IndesBody(true) };
	frame = new Frame(45, build, 25, 100);
	frame->Initialize(this);
}

FlameThrowerWeapon::~FlameThrowerWeapon() = default;

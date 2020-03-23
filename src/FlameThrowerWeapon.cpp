#include "FlameThrowerWeapon.h"
#include "Game.h"
#include "IndesBody.h"
#include "PlayerWeapon.h"
#include "Flamethrower.h"

FlameThrowerWeapon::FlameThrowerWeapon(glm::vec2 position)
{
	TheTextureManager::Instance()->load("../Assets/textures/Flamethrower.png", "Flamethrower", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Flamethrower");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);

	std::vector<ShipComponent> build = {
		IndesBody(true),IndesBody(true),IndesBody(true),IndesBody(true)
	};
	frame = new Frame(25, build, 4, 1);
	frame->Initialize(this);
	m_pflamethrower = new Flamethrower();
}

FlameThrowerWeapon::~FlameThrowerWeapon() = default;

void FlameThrowerWeapon::update()
{

	//PlayerWeapon::update();

	this->setPosition(glm::vec2(m_pflamethrower->getPosition().x + 1.0f, m_pflamethrower->getPosition().y));
	
}


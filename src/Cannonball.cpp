#include "Cannonball.h"
#include "Game.h"
#include "IndesBody.h"

Cannonball::Cannonball(glm::vec2 position, glm::vec2 velocity)
{
	name = "Cannonball";
	TheTextureManager::Instance()->load("../Assets/textures/Cannonball.png", "Cannonball", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Cannonball");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
	setVelocity(velocity);
	speed = velocity;
	std::vector<ShipComponent> build = { IndesBody(true) };
	frame = new Frame(25, build, 1, 1);
	frame->Initialize(this);



}

Cannonball::~Cannonball() = default;

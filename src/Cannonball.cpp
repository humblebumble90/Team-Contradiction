#include "CannonBall.h"
#include "Game.h"
#include "IndesBody.h"

CannonBall::CannonBall(glm::vec2 position, glm::vec2 velocity)
{
	TheTextureManager::Instance()->load("../Assets/textures/CannonBall.png", "CannonBall", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("CannonBall");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_HEIGHT * 0.5f, Config::SCREEN_WIDTH)); // This is not the final position
	setVelocity(velocity);

	std::vector<ShipComponent> build = { IndesBody(true) };
	frame = new Frame(25, build, 1, 1);
	frame->Initialize(this);



}

CannonBall::~CannonBall() = default;

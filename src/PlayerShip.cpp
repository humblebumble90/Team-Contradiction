#include "Game.h"
#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
	TheTextureManager::Instance()->load("../Assets/textures/plane.png",
		"player", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	setVelocity(glm::vec2(0.0f, 0.0f));
	m_speedMultiplier = 2;
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("player", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void PlayerShip::update()
{
	checkBounds();
}

void PlayerShip::clean()
{
}

void PlayerShip::move(Move newMove)
{
	auto position = getPosition();
	switch (newMove)
	{
	case RIGHT:
		//adds an x position
		setPosition(glm::vec2(position.x + m_speedMultiplier, position.y));
		std::cout << "Pressed RIGHT" << std::endl;
		break;
	case LEFT:
		setPosition(glm::vec2(position.x - m_speedMultiplier, position.y));
		std::cout << "Pressed LEFT" << std::endl;
		break;
	case UP:
		setPosition(glm::vec2(position.x, position.y - m_speedMultiplier));
		std::cout << "Pressed UP" << std::endl;
		break;
	case DOWN:
		setPosition(glm::vec2(position.x, position.y + m_speedMultiplier));
		std::cout << "Pressed DOWN" << std::endl;
		break;
	}
}

void PlayerShip::checkBounds()
{
	// check right bounds
	if (getPosition().x >= Config::SCREEN_WIDTH - getWidth() * 0.5f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH - getWidth() * 0.5f, getPosition().y));
	}

	// check left bounds
	if (getPosition().x <= getWidth() * 0.5f)
	{
		setPosition(glm::vec2(getWidth() * 0.5f, getPosition().y));
	}
}

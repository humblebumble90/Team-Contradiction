#include "Player.h"
#include "Game.h"
#include "Move.h"

Player::Player()
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
}

Player::~Player()
{
}

void Player::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("player", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Player::update()
{
	
}

void Player::clean()
{
}

bool Player::getIsMoving()
{
	return m_isMoving;
}

void Player::move(Move newMove)
{
	switch (newMove)
	{
	case Move::RIGHT:
		setVelocity(glm::vec2(1.0f * m_maxSpeed, 0.0f));
		break;
	case Move::LEFT:
		setVelocity(glm::vec2(-1.0f * m_maxSpeed, 0.0f));
		break;
	case Move::UP:
		break;
	}
}

void Player::setIsMoving(bool newMove)
{
	m_isMoving;
}

void Player::m_checkBounds()
{
	
}

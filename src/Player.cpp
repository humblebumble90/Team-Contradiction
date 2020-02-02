#include "Player.h"
#include "Game.h"

Player::Player()
{
	TheTextureManager::Instance()->load("../Assets/textures/plane.png", "player", TheGame::Instance()->getRenderer());
	setPosition(glm::vec2(0, 430.0f));

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	
}

Player::~Player()
{
}

void Player::draw()
{
	TheTextureManager::Instance()->draw("player", getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(), true);
}

void Player::update()
{
	Move();
}

void Player::clean()
{
}

void Player::Move()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				setVelocity(glm::vec2(0, -5.0f));
				setPosition(getPosition() + getVelocity());
				break;
			case SDLK_UP:
				setVelocity(glm::vec2(0, -5.0f));
				setPosition(getPosition() + getVelocity());
				break;
			case SDLK_s:
				setVelocity(glm::vec2(0, 5.0f));
				setPosition(getPosition() + getVelocity());
				break;
			case SDLK_DOWN:
				setVelocity(glm::vec2(0, 5.0f));
				setPosition(getPosition() + getVelocity());
				break;
			case SDLK_a:
				setVelocity(glm::vec2(5.0f,0));
				setPosition(getPosition() + getVelocity());
				break;
			case SDLK_LEFT:
				setVelocity(glm::vec2(5.0f, 0));
				setPosition(getPosition() + getVelocity());
				break;
			case SDLK_d:
				setVelocity(glm::vec2(-5.0f, 0));
				setPosition(getPosition() + getVelocity());
				break;
			case SDLK_RIGHT:
				setVelocity(glm::vec2(-5.0f, 0));
				setPosition(getPosition() + getVelocity());
				break;
			default:
				break;
			}
		}
	}
}

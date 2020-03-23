#include "explosion.h"
#include "Game.h"

Explosion::Explosion(std::string id):m_currentFrame(0),m_currentRow(0),animated(false),ID()
{
	ID = id;
	TheTextureManager::Instance()->load("../Assets/textures/explosion.png",
		ID, TheGame::Instance()->getRenderer());

	// framesize is 512 x 256

	auto size = TheTextureManager::Instance()->getTextureSize(ID);
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(400.0f, 300.0f));
	setIsColliding(false);
	setType(EXPLOSION);
	setState(IDLE);
}
Explosion::~Explosion() = default;
void Explosion::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	if(TheTextureManager::Instance()->getTexture(ID) != nullptr)
	{
		TheTextureManager::Instance()->drawFrame(ID, xComponent,
			yComponent, 64, 64, m_currentRow,
			m_currentFrame, TheGame::Instance()->getRenderer(),
			4, 4, 1.0f,
			TheGame::Instance()->getRenderer(), 180, 255, true);
	}
}

void Explosion::update()
{
}

void Explosion::clean()
{
		delete this;
}

void Explosion::setAnimated(bool newState)
{
	animated = newState;
	clean();
}

bool Explosion::getAnimated()
{
	return animated;
}

std::string Explosion::getID()
{
	return ID;
}

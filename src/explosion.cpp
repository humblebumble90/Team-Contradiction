#include "explosion.h"
#include "Game.h"

Explosion::Explosion()
{
	TheTextureManager::Instance()->load("../Assets/textures/explosion.png",
		"explosion", TheGame::Instance()->getRenderer());

	// framesize is 512 x 256

	auto size = TheTextureManager::Instance()->getTextureSize("explosion");
	setWidth(size.x);
	setHeight(size.y);

	std::cout << "width: " << size.x << " height: " << size.y << std::endl;
	setPosition(glm::vec2(400.0f, 300.0f));
	setIsColliding(false);
	setType(EXPLOSION);
	setState(IDLE);
	m_currentFrame = 0;
	m_currentRow = 0;
}
Explosion::~Explosion() = default;
void Explosion::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->drawFrame("explosion", xComponent,
		yComponent, 64, 64, m_currentRow,
		m_currentFrame, TheGame::Instance()->getRenderer(),
		4, 4, 1.0f,
		TheGame::Instance()->getRenderer(), 180, 255, true);
}

void Explosion::update()
{
}

void Explosion::clean()
{
}

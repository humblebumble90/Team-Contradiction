#include "Control_Img.h"
#include "TextureManager.h"
#include "Game.h"

Control_Img::Control_Img(std::string imagePath, std::string name, GameObjectType type, glm::vec2 position, bool isCentered)
	: m_name(name), m_isCentered(isCentered), m_alpha(255)
{
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
	setType(type);
	std::cout << "control image instantiated!\n";
}

Control_Img::~Control_Img()
{
}

void Control_Img::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Control_Img::update()
{
}

void Control_Img::clean()
{
}

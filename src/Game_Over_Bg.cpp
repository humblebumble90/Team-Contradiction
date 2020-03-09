#include "Game_Over_Bg.h"
#include "TextureManager.h"
#include "Game.h"

Game_Over_Bg::Game_Over_Bg(std::string imagePath, std::string name, GameObjectType type, glm::vec2 position, bool isCentered)
	: m_name(name), m_isCentered(isCentered), m_alpha(255)
{
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
	setType(type);
	std::cout << "Start_Scene_background instantiated!\n";
}

Game_Over_Bg::~Game_Over_Bg()
{
}

void Game_Over_Bg::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Game_Over_Bg::update()
{
}

void Game_Over_Bg::clean()
{
}

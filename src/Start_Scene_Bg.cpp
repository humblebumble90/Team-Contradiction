#include "Start_Scene_Bg.h"
#include "Game.h"

Start_Scene_Bg::Start_Scene_Bg(std::string imagePath, std::string name, GameObjectType type, glm::vec2 position, bool isCentered)
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

Start_Scene_Bg::~Start_Scene_Bg()
{
}

void Start_Scene_Bg::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Start_Scene_Bg::update()
{
}

void Start_Scene_Bg::clean()
{
}

#include "Start_Scene_Bg.h"
#include "Game.h"

Start_Scene_Bg::Start_Scene_Bg()
{
	changeTexture("Start_Scene_Bg");
	m_alpha = 255;
	m_isCentered = true;
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	setType(START_SCENE_BG);
	std::cout << "Start_Scene_background instantiated!\n";
}

Start_Scene_Bg::~Start_Scene_Bg()
{
}

void Start_Scene_Bg::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Start_Scene_Bg::update()
{
}

void Start_Scene_Bg::clean()
{
}

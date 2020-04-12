#include "TxtBx.h"
#include "TextureManager.h"
#include "Config.h"
#include "Game.h"

TxtBx::TxtBx()
{
	m_name = "txtBx";
	changeTexture(m_name);
	m_alpha = 122;
	m_isCentered = true;
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	setType(TXT_BX);
	//std::cout << "Start_Scene_background instantiated!\n";
}

TxtBx::~TxtBx()
{
}

void TxtBx::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void TxtBx::update()
{
}

void TxtBx::clean()
{
}

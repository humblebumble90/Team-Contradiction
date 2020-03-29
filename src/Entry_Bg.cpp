#include "Entry_Bg.h"
#include "TextureManager.h"
#include "Game.h"

Entry_Bg::Entry_Bg():m_name("entry"),m_alpha(255),m_isCentered(true)
{
	changeTexture("entry");
}

Entry_Bg::~Entry_Bg()
{
	delete this;
}

void Entry_Bg::draw()
{
	TheTextureManager::Instance()->draw
	(m_name, getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(), 0, m_alpha, m_isCentered);
}

void Entry_Bg::update()
{
}

void Entry_Bg::clean()
{
}

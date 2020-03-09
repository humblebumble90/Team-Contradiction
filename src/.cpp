#include "LivesLabel.h"
#include "Config.h"
#include "Game.h"
#include "Player.h"

LivesLabel::LivesLabel()
{
	SDL_Color yellow = { 255, 255, 0, 255 };
	("Lives: " + std::to_string((PlayerShip&)->getlive), "Consolas",
		24, yellow, glm::vec2(Config::SCREEN_WIDTH * 0.65f, 10.0f), TTF_STYLE_NORMAL, false);
}

LivesLabel::~LivesLabel()
{
}

void LivesLabel::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->drawText("Consolas", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void LivesLabel::update()
{
}

void LivesLabel::clean()
{
}

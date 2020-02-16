#include "Island.h"
#include "Game.h"

Island::Island()
{
	TheTextureManager::Instance()->load("../Assets/textures/island.png",
		"island", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("island");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::ISLAND);
	//setVelocity(glm::vec2(0.0f, 0.0f));

	TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);

}

Island::~Island()
{
}

void Island::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("island", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Island::update()
{
}

void Island::clean()
{
}

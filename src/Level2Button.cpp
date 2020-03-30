#include "Level2Button.h"
#include "Game.h"

Level2Button::Level2Button()
// call super constructor
	:Button(
		"Level2Button",
		LEVEL2_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.9f)), m_isClicked(false)
{

}

Level2Button::~Level2Button()
{
}

bool Level2Button::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
#include "Level3Button.h"
#include "Game.h"

Level3Button::Level3Button()
	: Button(
	"Level3Button",
		LEVEL3_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.7f, Config::SCREEN_HEIGHT * 0.95f)), m_isClicked(false)
{
}

Level3Button::~Level3Button()
{
}

bool Level3Button::ButtonClick()
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

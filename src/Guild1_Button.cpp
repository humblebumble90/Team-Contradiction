#include "Guild1_Button.h"
#include "Config.h"

Guild1_Button::Guild1_Button()
	: Button(
		"guild1_Button",
		GUILD1_BUTTON,
		glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.45f)), m_isClicked(false)
{
	
}

Guild1_Button::~Guild1_Button()
{
}

bool Guild1_Button::ButtonClick()
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

#include "Guild2_Button.h"
#include <glm/detail/type_vec2.hpp>
#include "Config.h"

Guild2_Button::Guild2_Button()
	: Button(
		"guild2_Button",
		GUILD2_BUTTON,
		glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.45f)), m_isClicked(false)
{

}

Guild2_Button::~Guild2_Button()
{
}

bool Guild2_Button::ButtonClick()
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

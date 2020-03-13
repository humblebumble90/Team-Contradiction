#include "StartButton.h"
#include "Game.h"

StartButton::StartButton()
// call super constructor
	:Button(
		"Level1Button",
		LEVEL1_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.9f)), m_isClicked(false)
{

}

StartButton::~StartButton()
{
}

bool StartButton::ButtonClick()
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

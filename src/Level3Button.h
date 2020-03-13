#pragma once
#ifndef __LEVEL_3_BUTTON__
#define __LEVEL_3_BUTTON__
#include "Button.h"

class Level3Button : public Button
{
public:
	Level3Button();
	~Level3Button();

	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif
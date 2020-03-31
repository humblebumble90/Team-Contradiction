#pragma once
#ifndef __LEVEL_2_BUTTON__
#define __LEVEL_2_BUTTON__

#include "Button.h"

class Level2Button : public Button
{
public:
	Level2Button();
	~Level2Button();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__LEVEL_2_BUTTON__) */

#pragma once
#ifndef __GUILD1_BUTTON__
#define __GUILD1_BUTTON__
#include "Button.h"

class Guild1_Button : public Button
{
public:
	Guild1_Button();
	~Guild1_Button();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /*Defined (__GUILD1_BUTTON__)*/

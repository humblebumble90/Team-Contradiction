#pragma once
#ifndef __GUILD2_BUTTON__
#define __GUILD2_BUTTON__
#include "Button.h"

class Guild2_Button : public Button
{
public:
	Guild2_Button();
	~Guild2_Button();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /*Defined (__GUILD2_BUTTON__)*/

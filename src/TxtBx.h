#pragma once
#include "DisplayObject.h"
#ifndef __TXTBX__
#define __TXTBX__
class TxtBx:public DisplayObject
{
public:
	TxtBx();
	~TxtBx();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif/*Defined (__TXTBX__)*/

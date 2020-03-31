#pragma once
#include "DisplayObject.h"
#ifndef __ENTRY_BG__
#define __ENTRY_BG__
#endif /*Defined (__ENTRY_BG__)*/
class Entry_Bg:public DisplayObject
{
public:
	Entry_Bg();
	~Entry_Bg();

	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
	
};
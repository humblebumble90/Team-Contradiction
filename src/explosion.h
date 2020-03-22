#include "DisplayObject.h"
#pragma once
#ifndef __EXPLOSION__
#define __EXPLOSION__
class Explosion : public DisplayObject
{
public:
	Explosion();
	~Explosion();

	void draw() override;
	void update() override;
	void clean() override;
	void setAnimated(bool newState);
	bool getAnimated();
private:
	int m_currentFrame;
	int m_currentRow;
	bool animated;
};
#endif/*Defined (__EXPLOSION__)*/
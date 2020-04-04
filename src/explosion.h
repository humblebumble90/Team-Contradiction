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
	void activate();
	void deActivate();
	bool Explosion::getIsActive();
private:
	int m_currentFrame;
	int m_currentRow;
	bool m_bisActive;
};
#endif/*Defined (__EXPLOSION__)*/
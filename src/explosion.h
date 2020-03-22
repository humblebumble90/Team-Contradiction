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
private:
	int m_currentFrame;
	int m_currentRow;
};
#endif/*Defined (__EXPLOSION__)*/
#pragma once
#ifndef __PLANE__
#define __PLANE__
#include "DisplayObject.h"
#include "Move.h"

class Plane : public DisplayObject
{
public:
	Plane();
	~Plane();
	
	void draw() override;
	void update() override;
	void clean() override;

	void move(Move newMove);

	//getters and setters
	bool getIsMoving();
	void setIsMoving(bool newState);
	
private:
	float m_maxSpeed;

	bool m_isMoving;

	void m_checkBounds();
};

#endif /* defined (__PLANE__) */
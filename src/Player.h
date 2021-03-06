#pragma once
#ifndef __Player__
#define __Player__

#include "GameObject.h"
#include "TextureManager.h"
#include "Move.h"
#include "PlayerWeaponTypes.h"

class Player : public GameObject {
public:
	Player();
	~Player();
	void draw() override;
	void update() override;
	void clean() override;
	bool getIsMoving();
	void move(Move newMove);
	void setIsMoving(bool newMove);
	void ChangeWeapon(PlayerWeaponType);
private:
	bool m_isMoving;
	float m_maxSpeed;
	void  m_checkBounds();
};


#endif /* defined (__Player__) */
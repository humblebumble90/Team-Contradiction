#pragma once
#ifndef __CANNON__
#define __CANNON__
#include "Weapon.h"

class Cannon : public Weapon {
public:
	Cannon();
	~Cannon();
	void Fire() override;
};
#endif
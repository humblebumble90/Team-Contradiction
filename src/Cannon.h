#pragma once
#ifndef __CANNON__
#define __CANNON__
#include "Weapon.h"
#include "Vector2.h"

class Cannon : public Weapon {
public:
	Cannon();
	~Cannon();
	void Fire();
	void Fire(Vector2 direction);
};
#endif
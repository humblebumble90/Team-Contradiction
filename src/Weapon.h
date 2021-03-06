#pragma once
#ifndef __WEAPON__
#define __WEAPON__

#include "ShipComponent.h"

//This is the base class for every weapon type that holds the method to instantiate them.
class Weapon : public ShipComponent
{
public:
	//constructor and destructor
	Weapon();
	~Weapon();

	//Method that fires the weapon
	void Fire();

};

#endif

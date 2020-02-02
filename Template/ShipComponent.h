#pragma once
#ifndef __SHIPCOMPONENT__
#define __SHIPCOMPONENT__
#endif
#include "Frame.h"
class ShipComponent
{
public:
	ShipComponent();
	virtual ~ShipComponent();
protected:
	Frame parent;
	float x, y;
	/*
	Currently, this class is unimplemented

	Essentially, this class is a type that is used to fill out the Frame class, thus building player and enemy GameObjects using identical objects
	As such, a ShipComponent called Blank and another called BasicBody need to be created
	Due to this method, it's also possible to create a third ShipComponent called IndestructibleBody (or IndesBody), which could be used by bosses...
	...essentially, IndesBody would act like a barrier (i.e. attacks that hit it vanish), thus forcing the player to attack certain parts of a boss...
	...to damage said boss.
	All weapons (Launcher (or whatever  it's called), Cannon, and Flamethrower) would likely be of type Weapon, which would inherit from ShipComponent
	This implimentation allows all sorts of items to be added to build the player and enemies (thus far, 6 item types have been named)
	Note that none of this construction affects sprites - the plan is for each frame to have a sprite, with the items in said frame not rendering
	As such, all frames will likely need to reflect the ShipComponents used to build said Frame (loading a bunch of sprites just doesn't sit right with me)
	*/
};